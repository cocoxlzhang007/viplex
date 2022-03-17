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
import "viplex/common"
import "encoding/json"
import "unsafe"

//公网初始化函数
func InitPublicNet()error{
	pn:=common.PublicNet{
		PublicModule:true,
		Encrypt:true,
		CertificatePath:"/root/go/src/viplex/ViplexCoreCentOS/bin/cert",
		Port:16603,
		HttpserverUrl:"localhost:80",
		HttpserverLocalPath:"",
	}
	pnjson,_:=json.Marshal(pn)
	pnjsonC:=C.CString(string(pnjson))

	C.nvInitPublicNetAsync(pnjsonC,(C.ExportViplexCallback)(C.connectCallback),(C.ExportViplexCallback)(C.disconnectCallback))
	C.free(unsafe.Pointer(pnjsonC))
	return nil
}

//export connectCallback
func connectCallback(C.uint16_t,*C.char){
	fmt.Println("")
}
//export disconnectCallback
func disconnectCallback(C.uint16_t,*C.char){}