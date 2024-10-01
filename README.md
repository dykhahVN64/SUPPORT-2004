# Người tạo ra thư viện Duy Khánh 1CDT22A
# Tôi tạo ra thư viện này với mục đích hỗm trợ việc kiểm tra môn thực tập vi xử lí

## Thư viện quản lí nút ấn và đèn Led 

## để cài đặt bạn cần Truy cập lên "GIT HUB" hoặc liên hệ trực tiếp với Tôi



### Đối với lớp Button 


+ Button(int buttuonPin) hàm này khởi tạo dối tượng buton với buttuonPin là chân bạn cần để khai báo nút nhấn


+ Với hàm nhannut(); sẽ là hàm bạn cần gọi ra để thực hiện việc nhấn nút


* Lưu ý (ở đây tôi tạo ra hàm nút nhấn này là chỉ được nhấn 2 lần nhấn lần 3 là sẽ quay về chế độ 1 đáp ứng yêu cầu đề lúc trước)


+ Tôi đã thêm một số hàm để chống dội phím nhấn vào bạn cần thực hiện kĩ mới nắm rõ được nó



### Đối với Led lớp (LedArray)

+ LedArray (int Pin1, int Pin2, int Pin3, int Pin4, int Pin5, int Pin6, int Pin7, int Pin8)
mục đích để khai báo các chân của led hãy nhớ rằng khai báo nó theo thứ tự mà tôi sắp xếp

+ ở đây tôi sẽ chú thích các hàm led để mọi người có thể dễ dàng sử dụng
========== Đây là hàm tắt dần các led còn gọi là led đuổi =========
- trenxuong(); hàm này là led sẽ chạy tắt dần từ trên xuống dưới theo thứ tự các chân mà bạn sắp xếp
- duoilen(); led chạy từ dưới lên trên
- trongrangoai(); led chạy tắt dần từ 2 con led trong ra ngoài
- ngoaivaotrong(); led chạy tắt dần từ ngoài vào trong

========= Đây là hàm bật các led sáng dần =================

- sangduoilentren(); mục đich của nó là các led sáng dần từ dưới lên trên 
- sangtrenxuongduoi(); các led sẽ sáng dần từ trên xuống dưới
- sangtrongrangoai(); sáng dần từ 2 led bên trong ra bên ngoài 
- sangngoaivaotrong(); sáng dần từ 2 con led từ bìa vào

- xepchongxuong();

- tatdantrenxuong();
- tatdanduoilen();
- tatdantrongrangoai();
- tatdanngoaivaotrong();
### ví dụ về cách dùng thư viện ###

#include<support.h> ////// đừng quên bước này

Button nut(0); 
// hàm này là hàm khởi tạo nút nhấn hàm 'Button' là bắt buộc bạn phải nhập vào vì nó là cấu trúc của thư viện
// còn đối với 'nut' biến này phải cách 'Button' 1 khoảng trắng đối với biến 'nut' bạn có thể thay đổi tùy vào mục đích của mình dể dễ quản lí hơn


LedArray led(8, 19, 10, 11, 1, 4, 14, 15); 
// khởi tạo các chân led với các đặt cấu trúc giống với nút nhấn bên trên

++++ đối 2 hàm trên bạn đã khởi tạo cac nút nhán và đèn led là ngõ ra hết bạn không cần phải khai báo nữa +++++++


void setup()
{
  // do không cần khai báo tôi sẽ để trông phần setup này.

}

void loop()
{
  int mode = nut.nhannut();         
  // 'nhannut' đây là hàm bắt buộc để bạn mới có thể sử dụng được thư viện nút nhấn cần 'nut' là do bạn tùy biến ở bên trên
  // mode này tôi tạo ra với mục đích dễ quản lí hơn không cần phải goi 'nut.nhannut' sẽ gọn chương trình bạn hơn
  if(mode == 1)
  {
    led.trenxuong(); 
    // hàm này với cấu trúc giống button bên trên
    // nó là trạng thái led của bạn 
  }
  if(mode == 2)
  {
    led.duoilen();
  }
}
// khi ấn lần 3 nó sẽ quay về chế độ 1 bạn không cần phải khai báo.