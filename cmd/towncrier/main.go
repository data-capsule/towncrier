package main

type RemoteConfig struct {
	Name string `json:"name"`
	Addr string `json:"addr"`
}

type Config struct {
	Name    string         `json:"name"`
	Port    int32          `json:"port"`
	Locals  []string       `json:"locals"`
	Remotes []RemoteConfig `json:"remotes"`
}

func main() {

}
