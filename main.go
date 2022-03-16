package main

import (
	"fmt"
	"viplex/cgo_interface"
)

func main() {
	cgo_interface.Init()
	fmt.Println("hello world")
}
