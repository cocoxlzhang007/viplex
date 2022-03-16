package main

/*
#cgo CPPFLAGS: -I/root/go/src/data_collect/ViplexCoreCentOS/include/
#cgo LDFLAGS: -L/root/go/src/data_collect/ViplexCoreCentOS/bin/ -lviplexcore
#include <stdio.h>
#include <stdlib.h>
#include "exportviplexcoreasync.h"
extern void ViplexCoreCallBack(uint16_t,char *);
*/
import "C"
import "encoding/json"
import "fmt"
import "unsafe"
import "os"
import "path/filepath"
import "path"
import "errors"

func GetPrograms() error {
	p := Programs{
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

func Init() error {
	dir, err := filepath.Abs(filepath.Dir(os.Args[0]))
	if err != nil {
		fmt.Println("get current path failed! err:", err)
		return err
	}
	sdkRootDir := path.Join(dir, "temp")
	CsdkRootDir := C.CString(sdkRootDir)

	c := Credentials{
		Company: "NovaStar",
		Phone:   "029-68216000",
		Email:   "hr@novastar.tech",
	}
	credentials, err := json.Marshal(c)
	Ccredentials := C.CString(string(credentials))
	

	result := C.nvInit(CsdkRootDir, Ccredentials)
	C.free(unsafe.Pointer(CsdkRootDir))
	C.free(unsafe.Pointer(Ccredentials))
	if result == 65286 {
		fmt.Println("log init failed")
		err := errors.New("log init failed")
		return err
	} else if result == 65287 {
		fmt.Println("database init failed")
		err := errors.New("database init failed")
		return err
	} else if result == 0 {
		fmt.Println("init success")
		return nil
	} else {
		fmt.Println("unknown error")
		err := errors.New("unknown error")
		return err
	}
}

//export ViplexCoreCallBack
func ViplexCoreCallBack(C.uint16_t, *C.char) {
	return
}
