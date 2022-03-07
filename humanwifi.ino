#include <ESP8266WiFi.h>

//wifi 연결코드
//그리고 추가사항으로 인터넷 연결 끊어지면 다시연결

//wifi
const char* ssid = "human"; //wifi 이름
const char* password = "0312395855"; //비밀번호

void setup()
{
  Serial.begin(9600); //전송속도
  Serial.println();

  WiFi.begin("human", "0312395855"); // WIFI연결 시작

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    // 네트워크의 연결 상태, 8개의 리턴값
    // STATUS와 WL_CONNECTED 값이 같은지를 통해 제대로 연결이 되있는지를 확인할 수 있다
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop("wifi 연결된 상태") {}
