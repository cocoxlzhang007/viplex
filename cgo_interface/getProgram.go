package cgo_interface

/*
#cgo CPPFLAGS: -I/root/go/src/data_collect/ViplexCoreCentOS/include/
#cgo LDFLAGS: -L/root/go/src/data_collect/ViplexCoreCentOS/bin/ -lviplexcore
#include <stdio.h>
#include <stdlib.h>
#include "exportviplexcoreasync.h"
extern void ViplexCoreCallBack(uint16_t,char *);
*/
import "C"
import (
	"encoding/json"
	"fmt"
	"unsafe"
	"viplex/common"
)

func GetPrograms() error {
	p := common.Programs{
		SN: "123456",
	}
	b, err := json.Marshal(&p)
	if err != nil {
		fmt.Println("json marshal input failed,err:", err)
		return err
	}
	C.nvGetProgramAsync((*C.char)(unsafe.Pointer(&b[0])), (C.ExportViplexCallback)(C.ViplexCoreCallBack))

	return nil
}

//export ViplexCoreCallBack
func ViplexCoreCallBack(C.uint16_t, *C.char) {
	return
}
