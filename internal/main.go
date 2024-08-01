package main

import (
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
	"path"
	"strings"
)

func main() {
	weeks := getWeekDir()

	for _, week := range weeks {
		ReadWeekAndUpdateMD(week)
	}

}

func ReadWeekAndUpdateMD(week os.DirEntry) error {
	problemDirs, err := os.ReadDir(week.Name())
	if err != nil {
		return err
	}

	md := NewMD(week.Name())

	for _, problemDir := range problemDirs {
		if !problemDir.IsDir() {
			continue
		}

		problem := NewProblem(problemDir.Name())
		md.AddProblem(problem)
		problemDirPath := path.Join(week.Name(), problemDir.Name())

		solvedByList, err := os.ReadDir(problemDirPath)
		if err != nil {
			log.Fatal(err)
		}

		md.StartSolved()
		for _, solvedBy := range solvedByList {
			md.AddSolvedBy(problemDir, solvedBy)
		}
		md.AddLine()
	}

	mdpath := path.Join(week.Name(), "README.md")
	os.WriteFile(mdpath, []byte(md.Body), 0644)

	return nil
}

func getWeekDir() []os.DirEntry {
	entrySet, err := os.ReadDir(".")
	if err != nil {
		log.Fatal(err)
	}

	result := make([]os.DirEntry, 0)
	for _, entry := range entrySet {
		if strings.HasPrefix(entry.Name(), "week") {
			result = append(result, entry)
		}
	}
	return result
}

//
//
//
// Define MD struct

type MD struct {
	Body string
}

func NewMD(week string) MD {
	return MD{
		Body: "# " + strings.ToUpper(week),
	}
}

func (m *MD) AddProblem(problem *Problem) {
	m.Body = m.Body + "\n\n### [" + problem.platform + "_" + problem.number + "](https://boj.kr/" + problem.number + ") : " + problem.name + "\n\n"
}

func (m *MD) StartSolved() {
	m.Body = m.Body + `|이름|풀이 링크|
|--|--|
`
}

func (m *MD) AddSolvedBy(problemDir os.DirEntry, solvedBy os.DirEntry) {
	name := solvedBy.Name()
	strs := strings.Split(name, ".")

	m.Body = m.Body +
		fmt.Sprintf("|%s| [link](%s)\n", strs[0], path.Join(problemDir.Name(), solvedBy.Name()))
}

func (m *MD) AddLine() {
	m.Body = m.Body + "---\n"
}

//
//
//
// Define Problem struct

type Problem struct {
	platform string
	number   string
	name     string
}

const (
	BAEKJOON   = "BOJ"
	CODEFORCES = "CF"
	ATCODER    = "AT"
	LEETCODE   = "LEET"
)

func NewProblem(name string) *Problem {
	strs := make([]string, 2)
	if name[0] == 'B' {
		strs[0] = BAEKJOON
		strs[1] = name[3:]
	}

	problem := &Problem{
		platform: strs[0],
		number:   strs[1],
	}
	problem.getProblemName()
	return problem
}

func (p *Problem) getProblemName() {
	resp, err := http.Get(fmt.Sprintf("https://solved.ac/api/v3/problem/show?problemId=%s", p.number))
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()

	body, err := io.ReadAll(resp.Body)

	var data map[string]interface{}
	err = json.Unmarshal(body, &data)
	if err != nil {
		log.Fatal(err)
	}

	problemName, ok := data["titleKo"].(string)
	if !ok {
		log.Fatal(err)
	}

	p.name = problemName
}