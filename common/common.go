package common

type Credentials struct {
	Company string `json:"company"`
	Phone   string `json:"phone"`
	Email   string `json:"email"`
}

type Programs struct {
	SN string `json:"sn"`
}

type PublicNet struct{
	PublicModule bool `json:"publicmodule"`
	Encrypt bool `json:"encrypt"`
	CertificatePath string `json:"certificatePath"`
	Port int `json:"port"`
	HttpserverUrl string `json:"httpserverUrl"`
	HttpserverLocalPath string `json:"httpserverLocalPath"`
}