#ifndef support_h
#define support_h
#include <Arduino.h>
/*
Hàm này tôi viết ra để ae dùng nút nhấn được linh hoạt hơn
không cần phải viết rườm rà.
*/
class Button {
  public:
  Button(int buttonPin);

  int nhannut();
 private:

 int _buttonPin; 
 int _coun;
 unsigned long _lastDebounceTime; 
 const unsigned long _debounceDelay = 50; 
};

/*
Đây là hàm khai báo các trạng thái chạy của led tôi 
tạo ra nó nhằm hỗ trợ ae đỡ 1 phần không cần phải khai báo.
*/

class LedArray
{
public:
LedArray(int Pin1, int Pin2, int Pin3, int Pin4, int Pin5, int Pin6, int Pin7, int Pin8 ); //dùng để nhận 8 chân led

void trenxuong();
void duoilen();
void trongrangoai();
void ngoaivaotrong();

void sangduoilentren();
void sangtrenxuongduoi();
void sangtrongrangoai();
void sangngoaivaotrong();

void xepchongxuong();

void tatdantrenxuong();
void tatdanduoilen();
void tatdantrongrangoai();
void tatdanngoaivaotrong();
private:
int _Pin1, _Pin2, _Pin3, _Pin4, _Pin5, _Pin6, _Pin7, _Pin8;

unsigned long _luuthoigian = 0;
const unsigned long _bienthoigian = 10;
int _step = 0;
};
#endif
