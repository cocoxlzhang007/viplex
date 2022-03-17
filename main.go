package main

import (
	"fmt"
	"time"
	"viplex/cgo_interface"
)

func main() {
	err:=cgo_interface.Init()
	if err!=nil{
		panic("init failed")
	}
	err = cgo_interface.InitPublicNet()
	if err!=nil{
		panic("initpublicnet failed")
	}
	fmt.Println("hello world")
	ticker:=time.NewTicker(time.Second)
	for{
		select{
		case <-ticker.C:
			continue
		}
	}
}
