# Thực hành lập trình ESP32-S3

Dự án gồm các bài thực hành điều khiển đèn LED sử dụng nút nhấn, trong đó dử dụng thư viện [OneButton](https://github.com/mathertel/OneButton) và thư viện `LED` (thư mục `lib/LED`). Mỗi bài thực thành ứng với một môi trường (env) riêng được đề cập trong `platformio.ini` nên chọn môi trường phù hợp 

## 1. Thông tin phần cứng

### Linh kiện sử dụng

- Board: **ESP32-S3 DevKitC-1 N16R8** (16 MB flash, 8 MB PSRAM)
- 2 LED, 2 điện trở 1k Ω
- 1 nút nhấn
- Test board, dây cắm

### Các chân sử dụng

| Env | File | Chân sử dụng |
|---|---|---|
| Blink_LED | Blink_LED.cpp | LED: GPIO4 |
| Double_Click | Double_Click.cpp | LED: GPIO4, nút: GPIO5 |
| Two_LED | Two_LED.cpp | LED1: GPIO4, LED2: GPIO6, nút: GPIO5 |

## 2. Chức năng

### Cấu trúc dự án

...
IOT_TUAN_3/
├── lib/LED/LED.h            # Lớp LED: on(), off(), flip(), blink(ms), loop()
├── src/
│   ├── Blink_LED.cpp        # LED nhấp nháy
│   ├── Double_Click.cpp     # 1 nút điều khiển 1 LED
│   └── Two_LED.cpp          # 1 nút điều khiển 2 LED
└── platformio.ini           # Mỗi ví dụ = 1 env
...

### Bài 1: Blink led
Lập trình ESP32-S3 điều khiển led nhấp nháy với chu kỳ 500ms

### Bài 2: Double click
Lập trình ESP32-S3 sử dụng nút nhấn điều khiển led với kịch bản :
- **Single click:** bật/tắt LED
- **Double click:** LED nhấp nháy 200 ms

Đang nhấp nháy mà single click thì LED dừng nhấp nháy và tắt.

### Bài 3: Two led
Lập trình ESP32-S3 sử dụng nút nhấn điều khiển led với kịch bản :

| Thao tác | Chức năng |
|---|---|
| **Double click** | Chuyển LED đang được điều khiển. LED được chọn sẽ sáng, LED còn lại tắt |
| **Single click** | Bật/tắt LED đang được điều khiển |
| **Giữ nút** | LED đang được điều khiển nhấp nháy 200 ms một lần |

Khi khởi động, chương trình chọn LED1 và LED1 sáng. Đang nhấp nháy mà single click thì LED dừng nhấp nháy và tắt.

### Cách chạy

1. Ở thanh trạng thái phía dưới, bấm vào ô chọn môi trường (mặc định hiện `Default (IOT_TUAN_3)`), rồi chọn env cần phù hợp với file cần upload. Ví dụ upload file `Double_Click` thì chọn `env:Double_Click`.
2. Bấm **Upload** (→).

Tham khảo: 
- https://docs.platformio.org/en/latest/projectconf/sections/env/options/build/build_src_filter.html
- https://docs.platformio.org/en/latest/projectconf/sections/env/index.html

## 3. Thư viện sử dụng

- [mathertel/OneButton](https://github.com/mathertel/OneButton) `^2.6.1`: nhận diện click, double click, giữ nút
- `lib/LED/LED.h`: lớp điều khiển LED không chặn (non-blocking), tác giả Nguyen Anh Tuan
