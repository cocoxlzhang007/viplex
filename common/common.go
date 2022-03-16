package common

type Credentials struct {
	Company string `json:"company"`
	Phone   string `json:"phone"`
	Email   string `json:"email"`
}

type Programs struct {
	SN string `json:"sn"`
}
