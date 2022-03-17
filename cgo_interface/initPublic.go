package cgo_interface

/*
#cgo CPPFLAGS: -I../ViplexCoreCentOS/include/
#cgo LDFLAGS: -L${SRCDIR}/../ViplexCoreCentOS/bin -lviplexcore
#include <stdio.h>
#include <stdlib.h>
#include "exportviplexcoreasync.h"
extern void connectCallback(uint16_t,char *);
extern void disconnectCallback(uint16_t,char *);
*/
import "C"
import (
	"encoding/json"
	"fmt"
	"unsafe"
	"viplex/common"
)

//公网初始化函数
func InitPublicNet() error {
	pn := common.PublicNetInput{
		PublicModule:        true,
		Encrypt:             true,
		CertificatePath:     "/root/go/src/viplex/ViplexCoreCentOS/bin/cert",
		Port:                16603,
		HttpserverUrl:       "localhost:80",
		HttpserverLocalPath: "",
	}
	pnjson, _ := json.Marshal(pn)
	pnjsonC := C.CString(string(pnjson))

	C.nvInitPublicNetAsync(pnjsonC, (C.ExportViplexCallback)(C.connectCallback), (C.ExportViplexCallback)(C.disconnectCallback))
	C.free(unsafe.Pointer(pnjsonC))
	return nil
}

//export connectCallback
func connectCallback(code C.uint16_t, result *C.char) {
	fmt.Println("connect Callback")
	retCode := int(code)
	resultJson := C.GoString(result)

	if retCode != 0 {
		fmt.Println("device connect failed")
		return
	}
	fmt.Println("deivce connect success")
	ret := &common.PublicNetOutput{}
	err := json.Unmarshal([]byte(resultJson), ret)
	if err != nil {
		fmt.Println("connectCallback input json data error,err:", err)
		return
	}

}

//export disconnectCallback
func disconnectCallback(code C.uint16_t, result *C.char) {
	fmt.Println("disconnect Callback")
	retCode := int(code)
	resultJson := C.GoString(result)

	if retCode != 0 {
		fmt.Println("device disconnect failed")
		return
	}
	fmt.Println("device disconnect success")
	ret := &common.PublicNetOutput{}
	err := json.Unmarshal([]byte(resultJson), ret)
	if err != nil {
		fmt.Println("disconnectCallback input json data error,err:", err)
		return
	}
}
