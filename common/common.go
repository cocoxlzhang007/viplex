package common

type Credentials struct {
	Company string `json:"company"`
	Phone   string `json:"phone"`
	Email   string `json:"email"`
}

type Programs struct {
	SN string `json:"sn"`
}

//初始化公网链接的入参
type PublicNetInput struct {
	PublicModule        bool   `json:"publicmodule"`
	Encrypt             bool   `json:"encrypt"`
	CertificatePath     string `json:"certificatePath"`
	Port                int    `json:"port"`
	HttpserverUrl       string `json:"httpserverUrl"`
	HttpserverLocalPath string `json:"httpserverLocalPath"`
}

//初始化公网链接的出参
type PublicNetOutput struct {
	Sn            string   `json:"sn"`
	ConnectId     string   `json:"connectid"`
	ProductName   string   `json:"productName"`
	Width         int      `json:"width"`
	Height        int      `json:"heigth"`
	Rotation      int      `json:"rotation"`
	AliasName     string   `json:"aliasName"`
	Logined       bool     `json:"logined"`
	Username      []string `json:"username"`
	TcpPort       int      `json:"tcpPort"`
	FtpPort       int      `json:"ftpPort"`
	SyssetFtpPort int      `json:"syssetFtpPort"`
	SyssetTcpPort int      `json:"syssetTcpPort"`
	Key           string   `json:"key"`
	Platform      string   `json:"platform"`
	Privacy       bool     `json:"privacy"`
	Password      string   `json:"password"`
	TerminalState int      `json:"terminalState"`
	IgnoreTime    int64    `json:"ignoreTime"`
	HasPassword   bool     `json:"hasPassword"`
}
