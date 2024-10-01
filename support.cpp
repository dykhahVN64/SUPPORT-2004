#include "Arduino.h"
#include "support.h"
Button::Button(int buttonPin)
{
  _buttonPin = buttonPin;
  pinMode(_buttonPin, INPUT_PULLUP);
  _coun = 0;
  _lastDebounceTime = 0;    
}

int Button::nhannut()
{
  int gt_button = digitalRead(_buttonPin);

  if(gt_button==LOW && (millis() - _lastDebounceTime) > _debounceDelay)
  {
     _lastDebounceTime = millis();
     _coun++;
     if(_coun >2)
     {
      _coun=1;
     }
  }
  return _coun;
}

//================ Hàm khởi tạo trạng thái led =======================


LedArray::LedArray(int Pin1, int Pin2, int Pin3, int Pin4, int Pin5, int Pin6, int Pin7, int Pin8 )
{
  _Pin1 = Pin1; // chân 1
  _Pin2 = Pin2; // chân 2
  _Pin3 = Pin3; // chân 3
  _Pin4 = Pin4; // chân 4
  _Pin5 = Pin5; // chân 5
  _Pin6 = Pin6; // chân 6
  _Pin7 = Pin7; // chân 7
  _Pin8 = Pin8; // chân 8

  // Thiết lập các chân là ngõ ra 
  pinMode(_Pin1,OUTPUT); //1
  pinMode(_Pin2,OUTPUT); //2 
  pinMode(_Pin3,OUTPUT); //3
  pinMode(_Pin4,OUTPUT); //4
  pinMode(_Pin5,OUTPUT); //5 
  pinMode(_Pin6,OUTPUT); //6
  pinMode(_Pin7,OUTPUT); //7
  pinMode(_Pin8,OUTPUT); //8

  // Quy định tắt tất cả các led 
  digitalWrite(_Pin1,LOW);
  digitalWrite(_Pin2,LOW);
  digitalWrite(_Pin3,LOW);
  digitalWrite(_Pin4,LOW);
  digitalWrite(_Pin5,LOW);
  digitalWrite(_Pin6,LOW);
  digitalWrite(_Pin7,LOW);
  digitalWrite(_Pin8,LOW);

}

//======= trường hợp 1 =========
void LedArray::trenxuong()
{
  if((millis() - _luuthoigian) >= _bienthoigian )
  {
    _luuthoigian = millis();

    // bắt đầu vào hàm led
    switch(_step)
    {
      case 0:
      digitalWrite(_Pin1,HIGH);
      delay(20);
      digitalWrite(_Pin1,LOW);
      _step = 1;
      break;
      
      

      case 1:
      digitalWrite(_Pin2,HIGH);
      delay(20);
      digitalWrite(_Pin2,LOW);
      _step = 2;
      break;

      

      case 2:
      digitalWrite(_Pin3,HIGH);
      delay(20);
      digitalWrite(_Pin3,LOW);
      _step = 3;
      break;

      

      case 3:
      digitalWrite(_Pin4,HIGH);
      delay(20);
      digitalWrite(_Pin4,LOW);
      _step = 4;
      break;

      
      case 4:
      digitalWrite(_Pin5,HIGH);
      delay(20);
       digitalWrite(_Pin5,LOW);
      _step = 5;
      break;

      

      case 5:
      digitalWrite(_Pin6,HIGH);
      delay(20);
      digitalWrite(_Pin6,LOW);
      _step = 6;
      break;

      

      case 6:
      digitalWrite(_Pin7,HIGH);
      delay(20);
      digitalWrite(_Pin7,LOW);
      _step = 7;
      break;

      

      case 7:
      digitalWrite(_Pin8,HIGH);
      delay(20);
      digitalWrite(_Pin8,LOW);
      _step = 0;
      break;

     

    }
  }
}

void LedArray::duoilen()
{
  if((millis() - _luuthoigian) >= _bienthoigian )
  {
    _luuthoigian = millis();

    // bắt đầu vào hàm led
    switch(_step)
    {
      case 0:
      digitalWrite(_Pin8,HIGH);
      delay(20);
      digitalWrite(_Pin8,LOW);
      _step = 1;
      break;
      
      

      case 1:
      digitalWrite(_Pin7,HIGH);
      delay(20);
      digitalWrite(_Pin7,LOW);
      _step = 2;
      break;

      

      case 2:
      digitalWrite(_Pin6,HIGH);
      delay(20);
      digitalWrite(_Pin6,LOW);
      _step = 3;
      break;

      

      case 3:
      digitalWrite(_Pin5,HIGH);
      delay(20);
      digitalWrite(_Pin5,LOW);
      _step = 4;
      break;

      
      case 4:
      digitalWrite(_Pin4,HIGH);
      delay(20);
       digitalWrite(_Pin4,LOW);
      _step = 5;
      break;

      

      case 5:
      digitalWrite(_Pin3,HIGH);
      delay(20);
      digitalWrite(_Pin3,LOW);
      _step = 6;
      break;

      

      case 6:
      digitalWrite(_Pin2,HIGH);
      delay(20);
      digitalWrite(_Pin2,LOW);
      _step = 7;
      break;

      

      case 7:
      digitalWrite(_Pin1,HIGH);
      delay(20);
      digitalWrite(_Pin1,LOW);
      _step = 0;
      break;

     

    }
  }
}

void LedArray::trongrangoai()
{
  if((millis() - _luuthoigian)>= _bienthoigian)
  {
    _luuthoigian = millis();

    switch(_step)
    {
      case 0:
      digitalWrite(_Pin4,HIGH);
      digitalWrite(_Pin5,HIGH);
      delay(20);
      digitalWrite(_Pin1,LOW);
      digitalWrite(_Pin2,LOW);
      digitalWrite(_Pin3,LOW);
      
      digitalWrite(_Pin6,LOW);
      digitalWrite(_Pin7,LOW);
      digitalWrite(_Pin8,LOW);
      digitalWrite(_Pin4,LOW);
      digitalWrite(_Pin5,LOW);
      _step = 1;
      break;
     case 1:
     digitalWrite(_Pin3,HIGH);
     digitalWrite(_Pin6,HIGH);
     delay(20);
      digitalWrite(_Pin1,LOW);
      digitalWrite(_Pin2,LOW);
      
      digitalWrite(_Pin4,LOW);
      digitalWrite(_Pin5,LOW);
      
      digitalWrite(_Pin7,LOW);
      digitalWrite(_Pin8,LOW);
      digitalWrite(_Pin3,LOW);
      digitalWrite(_Pin6,LOW);
      _step = 2;
      break;
      case 2:
     digitalWrite(_Pin2,HIGH);
     digitalWrite(_Pin7,HIGH);
     
     delay(20);
      digitalWrite(_Pin1,LOW);
      
      digitalWrite(_Pin3,LOW);
      digitalWrite(_Pin4,LOW);
      digitalWrite(_Pin5,LOW);
      digitalWrite(_Pin6,LOW);
      
      digitalWrite(_Pin8,LOW);
      digitalWrite(_Pin2,LOW);
     digitalWrite(_Pin7,LOW);
      _step = 3;
      break;

      case 3:
      digitalWrite(_Pin1,HIGH);
      digitalWrite(_Pin8,HIGH);
     delay(20);
      digitalWrite(_Pin1,LOW);
      
      digitalWrite(_Pin3,LOW);
      digitalWrite(_Pin4,LOW);
      digitalWrite(_Pin5,LOW);
      digitalWrite(_Pin6,LOW);
      
      digitalWrite(_Pin8,LOW);
      digitalWrite(_Pin2,LOW);
     digitalWrite(_Pin7,LOW);
      _step = 4;
      break;
    
     case 4:
     digitalWrite(_Pin1,LOW);
      digitalWrite(_Pin2,LOW);
      digitalWrite(_Pin3,LOW);
      
      digitalWrite(_Pin6,LOW);
      digitalWrite(_Pin7,LOW);
      digitalWrite(_Pin8,LOW);
      digitalWrite(_Pin4,LOW);
      digitalWrite(_Pin5,LOW);
      _step = 0;
      break;

    }

  }
}

void LedArray::ngoaivaotrong()
{
  if((millis() - _luuthoigian)>= _bienthoigian)
  {
    _luuthoigian = millis();

    switch(_step)
    {
      case 0:
      digitalWrite(_Pin1,HIGH);
      digitalWrite(_Pin8,HIGH);
      delay(20);
      digitalWrite(_Pin1,LOW);
      digitalWrite(_Pin2,LOW);
      digitalWrite(_Pin3,LOW);
      
      digitalWrite(_Pin6,LOW);
      digitalWrite(_Pin7,LOW);
      digitalWrite(_Pin8,LOW);
      digitalWrite(_Pin4,LOW);
      digitalWrite(_Pin5,LOW);
      _step = 1;
      break;
     case 1:
     digitalWrite(_Pin2,HIGH);
     digitalWrite(_Pin7,HIGH);
     delay(20);
      digitalWrite(_Pin1,LOW);
      digitalWrite(_Pin2,LOW);
      
      digitalWrite(_Pin4,LOW);
      digitalWrite(_Pin5,LOW);
      
      digitalWrite(_Pin7,LOW);
      digitalWrite(_Pin8,LOW);
      digitalWrite(_Pin3,LOW);
      digitalWrite(_Pin6,LOW);
      _step = 2;
      break;
      case 2:
     digitalWrite(_Pin3,HIGH);
     digitalWrite(_Pin6,HIGH);
     
     delay(20);
      digitalWrite(_Pin1,LOW);
      
      digitalWrite(_Pin3,LOW);
      digitalWrite(_Pin4,LOW);
      digitalWrite(_Pin5,LOW);
      digitalWrite(_Pin6,LOW);
      
      digitalWrite(_Pin8,LOW);
      digitalWrite(_Pin2,LOW);
     digitalWrite(_Pin7,LOW);
      _step = 3;
      break;

      case 3:
      digitalWrite(_Pin4,HIGH);
      digitalWrite(_Pin5,HIGH);
     delay(20);
      digitalWrite(_Pin1,LOW);
      
      digitalWrite(_Pin3,LOW);
      digitalWrite(_Pin4,LOW);
      digitalWrite(_Pin5,LOW);
      digitalWrite(_Pin6,LOW);
      
      digitalWrite(_Pin8,LOW);
      digitalWrite(_Pin2,LOW);
     digitalWrite(_Pin7,LOW);
      _step = 4;
      break;
    
     case 4:
     digitalWrite(_Pin1,LOW);
      digitalWrite(_Pin2,LOW);
      digitalWrite(_Pin3,LOW);
      
      digitalWrite(_Pin6,LOW);
      digitalWrite(_Pin7,LOW);
      digitalWrite(_Pin8,LOW);
      digitalWrite(_Pin4,LOW);
      digitalWrite(_Pin5,LOW);
      _step = 0;
      break;

    }

  }
}

void LedArray::sangduoilentren()
{
  if((millis() - _luuthoigian) >= _bienthoigian)
  {
    _luuthoigian = millis();

    switch (_step)
    {
      case 0:
      digitalWrite(_Pin8,HIGH);
      delay(20);
       _step =1;
       break;

       case 1:
       digitalWrite(_Pin7,HIGH);
       delay(20);
       _step = 2;
       break;

       case 2:
       digitalWrite(_Pin6,HIGH);
       delay(20);
       _step =3;
       break;

       case 3:
       digitalWrite(_Pin5,HIGH);
       delay(20);
       _step =4;
       break;

       case 4:
       digitalWrite(_Pin4,HIGH);
       delay(20);
       _step =5;
       break;

       case 5:
       digitalWrite(_Pin3,HIGH);
       delay(20);
       _step =6;
       break;

       case 6:
       digitalWrite(_Pin2,HIGH);
       delay(20);
       _step =7;
       break;

       case 7:
       digitalWrite(_Pin1,HIGH);
       delay(20);
       _step =8;
       break;

       case 8:
       digitalWrite(_Pin1,LOW);
       digitalWrite(_Pin2,LOW);
       digitalWrite(_Pin3,LOW);
       digitalWrite(_Pin4,LOW);
       digitalWrite(_Pin5,LOW);
       digitalWrite(_Pin6,LOW);
       digitalWrite(_Pin7,LOW);
       digitalWrite(_Pin8,LOW);
       _step =0;
       break;

    }
  }
}

void LedArray::sangtrenxuongduoi()
{
  if((millis() - _luuthoigian) >= _bienthoigian)
  {
    _luuthoigian = millis();

    switch (_step)
    {
      case 0:
      digitalWrite(_Pin1,HIGH);
      delay(20);
       _step =1;
       break;

       case 1:
       digitalWrite(_Pin2,HIGH);
       delay(20);
       _step = 2;
       break;

       case 2:
       digitalWrite(_Pin3,HIGH);
       delay(20);
       _step =3;
       break;

       case 3:
       digitalWrite(_Pin4,HIGH);
       delay(20);
       _step =4;
       break;

       case 4:
       digitalWrite(_Pin5,HIGH);
       delay(20);
       _step =5;
       break;

       case 5:
       digitalWrite(_Pin6,HIGH);
       delay(20);
       _step =6;
       break;

       case 6:
       digitalWrite(_Pin7,HIGH);
       delay(20);
       _step =7;
       break;

       case 7:
       digitalWrite(_Pin8,HIGH);
       delay(20);
       _step =8;
       break;

       case 8:
       digitalWrite(_Pin1,LOW);
       digitalWrite(_Pin2,LOW);
       digitalWrite(_Pin3,LOW);
       digitalWrite(_Pin4,LOW);
       digitalWrite(_Pin5,LOW);
       digitalWrite(_Pin6,LOW);
       digitalWrite(_Pin7,LOW);
       digitalWrite(_Pin8,LOW);
       _step =0;
       break;

    }
  }
}

void LedArray::sangtrongrangoai()
{
  if((millis() - _luuthoigian) >= _bienthoigian)
  {
    _luuthoigian = millis();

    switch(_step)
    {
      case 0:
      digitalWrite(_Pin4,HIGH);
      digitalWrite(_Pin5,HIGH);
      delay(20);
      _step = 1;
      break;

      case 1:
      digitalWrite(_Pin3,HIGH);
      digitalWrite(_Pin6,HIGH);
      delay(20);
      _step = 2;
      break;

      case 2:
      digitalWrite(_Pin2,HIGH);
      digitalWrite(_Pin7,HIGH);
      delay(20);
      _step = 3;
      break;

      case 3:
      digitalWrite(_Pin1,HIGH);
      digitalWrite(_Pin8,HIGH);
      delay(20);
      _step = 4;
      break;

      case 4:
      digitalWrite(_Pin1,LOW);
      digitalWrite(_Pin2,LOW);
      digitalWrite(_Pin3,LOW);
      digitalWrite(_Pin4,LOW);
      digitalWrite(_Pin5,LOW);
      digitalWrite(_Pin6,LOW);
      digitalWrite(_Pin7,LOW);
      digitalWrite(_Pin8,LOW);
      _step = 0;
      break;

    }
  }
}

void LedArray::sangngoaivaotrong()
{
  if((millis() - _luuthoigian) >= _bienthoigian)
  {
    _luuthoigian = millis();

    switch(_step)
    {
     
  break;
      case 0:
      digitalWrite(_Pin1,HIGH);
      digitalWrite(_Pin8,HIGH);
      delay(20);
      _step = 1;
      break;

      case 1:
      digitalWrite(_Pin2,HIGH);
      digitalWrite(_Pin7,HIGH);
      delay(20);
      _step = 2;
      break;

      case 2:
      digitalWrite(_Pin3,HIGH);
      digitalWrite(_Pin6,HIGH);
      delay(20);
      _step = 3;
      break;

      case 3:
      digitalWrite(_Pin4,HIGH);
      digitalWrite(_Pin5,HIGH);
      delay(20);
      _step = 4;
      break;

      case 4:
      digitalWrite(_Pin1,LOW);
      digitalWrite(_Pin2,LOW);
      digitalWrite(_Pin3,LOW);
      digitalWrite(_Pin4,LOW);
      digitalWrite(_Pin5,LOW);
      digitalWrite(_Pin6,LOW);
      digitalWrite(_Pin7,LOW);
      digitalWrite(_Pin8,LOW);
      _step = 0;
      break;

    }
  }
}

void LedArray::xepchongxuong()
{
  if((millis() - _luuthoigian) >= _bienthoigian)
  {
    _luuthoigian = millis();

    switch(_step)
{


  case 0:
    digitalWrite(_Pin1, HIGH);
    delay(10);
    _step = 1; // Chuyển sang bước tiếp theo
    break;

  case 1:
    digitalWrite(_Pin1, LOW);
    digitalWrite(_Pin2, HIGH);
    delay(10);
    _step = 2; // Chuyển sang bước tiếp theo
    break;

  case 2:
    digitalWrite(_Pin2, LOW);
    digitalWrite(_Pin3, HIGH);
    delay(10);
    _step = 3; // Chuyển sang bước tiếp theo
    break;

  case 3:
    digitalWrite(_Pin3, LOW);
    digitalWrite(_Pin4, HIGH);
    delay(10);
    _step = 4; // Chuyển sang bước tiếp theo
    break;

  case 4:
    digitalWrite(_Pin4, LOW);
    digitalWrite(_Pin5, HIGH);
    delay(10);
    _step = 5; // Chuyển sang bước tiếp theo
    break;

  case 5:
    digitalWrite(_Pin5, LOW);
    digitalWrite(_Pin6, HIGH);
    delay(10);
    _step = 6; // Chuyển sang bước tiếp theo
    break;

  case 6:
    digitalWrite(_Pin6, LOW);
    digitalWrite(_Pin7, HIGH);
    delay(10);
    _step = 7; // Chuyển sang bước tiếp theo
    break;

  case 7:
    digitalWrite(_Pin7, LOW);
    digitalWrite(_Pin8, HIGH);
    
    _step = 8; // Đặt lại về đầu
    break;
 case 8:
    digitalWrite(_Pin1, HIGH);
    delay(10);
    _step = 9; // Chuyển sang bước tiếp theo
    break;

  case 9:  
    digitalWrite(_Pin1, LOW);
    digitalWrite(_Pin2, HIGH);
    delay(10);
    _step = 10; // Chuyển sang bước tiếp theo
    break;

  case 10:
   digitalWrite(_Pin2, LOW);
    digitalWrite(_Pin3, HIGH);
    delay(10);
    _step = 11; // Chuyển sang bước tiếp theo
    break;
   
  case 11:
  digitalWrite(_Pin3, LOW);
  digitalWrite(_Pin4, HIGH);
    delay(10);
    _step = 12; // Chuyển sang bước tiếp theo
    break;

  case 12:
  digitalWrite(_Pin4, LOW);
  digitalWrite(_Pin5, HIGH);
    delay(10);
    _step = 13; // Chuyển sang bước tiếp theo
    break;

  case 13:
  digitalWrite(_Pin5, LOW);
  digitalWrite(_Pin6, HIGH);
    delay(10);
    _step = 14; // Chuyển sang bước tiếp theo
    break;
  
  case 14:
  digitalWrite(_Pin6, LOW);
  digitalWrite(_Pin7, HIGH);
    
    _step = 15; // Chuyển sang bước tiếp theo
    break;

  case 15:
    digitalWrite(_Pin1, HIGH);
    delay(10);
    _step = 16; // Chuyển sang bước tiếp theo
    break;

  case 16:  
    digitalWrite(_Pin1, LOW);
    digitalWrite(_Pin2, HIGH);
    delay(10);
    _step = 17; // Chuyển sang bước tiếp theo
    break;

  case 17:
   digitalWrite(_Pin2, LOW);
    digitalWrite(_Pin3, HIGH);
    delay(10);
    _step = 18; // Chuyển sang bước tiếp theo
    break;
   
  case 18:
  digitalWrite(_Pin3, LOW);
  digitalWrite(_Pin4, HIGH);
    delay(10);
    _step = 19; // Chuyển sang bước tiếp theo
    break;

  case 19:
  digitalWrite(_Pin4, LOW);
  digitalWrite(_Pin5, HIGH);
    delay(10);
    _step = 20; // Chuyển sang bước tiếp theo
    break;

  case 20:
  digitalWrite(_Pin5, LOW);
  digitalWrite(_Pin6, HIGH);
   
    _step = 21; // Chuyển sang bước tiếp theo
    break;
  
  case 21:
    digitalWrite(_Pin1, HIGH);
    delay(10);
    _step = 22; // Chuyển sang bước tiếp theo
    break;

  case 22:  
    digitalWrite(_Pin1, LOW);
    digitalWrite(_Pin2, HIGH);
    delay(10);
    _step = 23; // Chuyển sang bước tiếp theo
    break;

  case 23:
   digitalWrite(_Pin2, LOW);
    digitalWrite(_Pin3, HIGH);
    delay(10);
    _step = 24; // Chuyển sang bước tiếp theo
    break;
   
  case 24:
  digitalWrite(_Pin3, LOW);
  digitalWrite(_Pin4, HIGH);
    delay(10);
    _step = 25; // Chuyển sang bước tiếp theo
    break;

  case 25:
  digitalWrite(_Pin4, LOW);
  digitalWrite(_Pin5, HIGH);
    
    _step = 26; // Chuyển sang bước tiếp theo
    break;
  
  case 26:
    digitalWrite(_Pin1, HIGH);
    delay(10);
    _step = 27; // Chuyển sang bước tiếp theo
    break;

  case 27:  
    digitalWrite(_Pin1, LOW);
    digitalWrite(_Pin2, HIGH);
    delay(10);
    _step = 28; // Chuyển sang bước tiếp theo
    break;

  case 28:
   digitalWrite(_Pin2, LOW);
    digitalWrite(_Pin3, HIGH);
    delay(10);
    _step = 29; // Chuyển sang bước tiếp theo
    break;
   
  case 29:
  digitalWrite(_Pin3, LOW);
  digitalWrite(_Pin4, HIGH);
   
    _step = 30; // Chuyển sang bước tiếp theo
    break;

  case 30:
    digitalWrite(_Pin1, HIGH);
    delay(10);
    _step = 31; // Chuyển sang bước tiếp theo
    break;

  case 31:  
    digitalWrite(_Pin1, LOW);
    digitalWrite(_Pin2, HIGH);
    delay(10);
    _step = 32; // Chuyển sang bước tiếp theo
    break;

  case 32:
   digitalWrite(_Pin2, LOW);
    digitalWrite(_Pin3, HIGH);
   
    _step = 33; // Chuyển sang bước tiếp theo
    break;
  
  case 33:
    digitalWrite(_Pin1, HIGH);
    delay(10);
    _step = 34; // Chuyển sang bước tiếp theo
    break;

  case 34:  
    digitalWrite(_Pin1, LOW);
    digitalWrite(_Pin2, HIGH);
    
    _step = 35; // Chuyển sang bước tiếp theo
    break;

  case 35:
    digitalWrite(_Pin1, HIGH);
    
    _step = 36; // Chuyển sang bước tiếp theo
    break;

  
  case 36:
  digitalWrite(_Pin1,LOW);
  digitalWrite(_Pin2,LOW);
  digitalWrite(_Pin3,LOW);
  digitalWrite(_Pin4,LOW);
  digitalWrite(_Pin5,LOW);
  digitalWrite(_Pin6,LOW);
  digitalWrite(_Pin7,LOW);
  digitalWrite(_Pin8,LOW);
  _step =0;
  break;
  }
 }
}

void LedArray::tatdantrenxuong()
{
  if((millis() - _luuthoigian) >= _bienthoigian)
  {
    _luuthoigian = millis();
    switch(_step)
    {
    case 0:
    digitalWrite(_Pin1,HIGH);
    digitalWrite(_Pin2,HIGH);
    digitalWrite(_Pin3,HIGH);
    digitalWrite(_Pin4,HIGH);
    digitalWrite(_Pin5,HIGH);
    digitalWrite(_Pin6,HIGH);
    digitalWrite(_Pin7,HIGH);
    digitalWrite(_Pin8,HIGH);
    _step=1;
    break;
    case 1:
    digitalWrite(_Pin1,LOW);
    delay(20);
    _step =2;
    break;
     case 2:
    digitalWrite(_Pin2,LOW);
    delay(20);
    _step =3;
    break;
     case 3:
    digitalWrite(_Pin3,LOW);
    delay(20);
    _step =4;
    break;
     case 4:
    digitalWrite(_Pin4,LOW);
    delay(20);
    _step =5;
    break;
     case 5:
    digitalWrite(_Pin5,LOW);
    delay(20);
    _step =6;
    break;
     case 6:
    digitalWrite(_Pin6,LOW);
    delay(20);
    _step =7;
    break;
     case 7:
    digitalWrite(_Pin7,LOW);
    delay(20);
    _step =8;
    break;
     case 8:
    digitalWrite(_Pin8,LOW);
    delay(20);
    _step =0;
    break;
    }
  }
}

void LedArray::tatdanduoilen()
{
  if((millis() - _luuthoigian) >= _bienthoigian)
  {
    _luuthoigian = millis();
    switch(_step)
    {
    case 0:
    digitalWrite(_Pin1,HIGH);
    digitalWrite(_Pin2,HIGH);
    digitalWrite(_Pin3,HIGH);
    digitalWrite(_Pin4,HIGH);
    digitalWrite(_Pin5,HIGH);
    digitalWrite(_Pin6,HIGH);
    digitalWrite(_Pin7,HIGH);
    digitalWrite(_Pin8,HIGH);
    _step=1;
    break;
    case 1:
    digitalWrite(_Pin8,LOW);
    delay(20);
    _step =2;
    break;
     case 2:
    digitalWrite(_Pin7,LOW);
    delay(20);
    _step =3;
    break;
     case 3:
    digitalWrite(_Pin6,LOW);
    delay(20);
    _step =4;
    break;
     case 4:
    digitalWrite(_Pin5,LOW);
    delay(20);
    _step =5;
    break;
     case 5:
    digitalWrite(_Pin4,LOW);
    delay(20);
    _step =6;
    break;
     case 6:
    digitalWrite(_Pin3,LOW);
    delay(20);
    _step =7;
    break;
     case 7:
    digitalWrite(_Pin2,LOW);
    delay(20);
    _step =8;
    break;
     case 8:
    digitalWrite(_Pin1,LOW);
    delay(20);
    _step =0;
    break;
    }
  }
}



void LedArray::tatdantrongrangoai()
{
  if((millis() - _luuthoigian) >= _bienthoigian)
  {
    _luuthoigian = millis();
    switch(_step)
    {
    case 0:
    digitalWrite(_Pin1,HIGH);
    digitalWrite(_Pin2,HIGH);
    digitalWrite(_Pin3,HIGH);
    digitalWrite(_Pin4,HIGH);
    digitalWrite(_Pin5,HIGH);
    digitalWrite(_Pin6,HIGH);
    digitalWrite(_Pin7,HIGH);
    digitalWrite(_Pin8,HIGH);
    _step= 1;
    break;
    
    case 1:
    digitalWrite(_Pin4,LOW);
    digitalWrite(_Pin5,LOW);
    delay(20);
    _step = 2;
    break;
    
    case 2:
    digitalWrite(_Pin3,LOW);
    digitalWrite(_Pin6,LOW);
    delay(20);
    _step = 3;
    break;

    case 3:
    digitalWrite(_Pin2,LOW);
    digitalWrite(_Pin7,LOW);
    delay(20);
    _step = 4;
    break;

    case 4:
    digitalWrite(_Pin1,LOW);
    digitalWrite(_Pin8,LOW);
    delay(20);
    _step = 0;
    break;
     }

  }
}      


void LedArray::tatdanngoaivaotrong()
{
  if((millis() - _luuthoigian) >= _bienthoigian)
  {
    _luuthoigian = millis();
    switch(_step)
    {
    case 0:
    digitalWrite(_Pin1,HIGH);
    digitalWrite(_Pin2,HIGH);
    digitalWrite(_Pin3,HIGH);
    digitalWrite(_Pin4,HIGH);
    digitalWrite(_Pin5,HIGH);
    digitalWrite(_Pin6,HIGH);
    digitalWrite(_Pin7,HIGH);
    digitalWrite(_Pin8,HIGH);
    _step= 1;
    break;
    
    case 1:
    digitalWrite(_Pin1,LOW);
    digitalWrite(_Pin8,LOW);
    delay(20);
    _step = 2;
    break;
    
    case 2:
    digitalWrite(_Pin2,LOW);
    digitalWrite(_Pin7,LOW);
    delay(20);
    _step = 3;
    break;

    case 3:
    digitalWrite(_Pin3,LOW);
    digitalWrite(_Pin6,LOW);
    delay(20);
    _step = 4;
    break;

    case 4:
    digitalWrite(_Pin4,LOW);
    digitalWrite(_Pin5,LOW);
    delay(20);
    _step = 0;
    break;
     }

  }
}      