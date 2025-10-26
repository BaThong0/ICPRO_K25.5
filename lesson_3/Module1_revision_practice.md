1. Viết 1 dòng code để bật bit thứ n của x. <br>
x |= 1 << n; 
2. Viết 1 dòng code để tắt bit thứ n của x. <br>
x &= ~(1 << n);    
3. Viết 1 dòng code để đảo bit thứ n của x. <br>
x ^= 1 << n;
4. Viết 1 dòng code để kiểm tra bit thứ n có bật không. <br>
if(x && (1<<n));
5. Viết 1 dòng code để hoán đổi 2 số a và b không dùng biến thứ 3 <br>
a ^= b; b ^= a; a ^= b hoặc a = a + b; b = a - b; a = a - b;
6. Làm thế nào để kiểm tra 1 số có phải lũy thừa của 2 hay không? <br>
if(n*(n-1) == 0);
7. Viết 1 dòng code để kiểm tra n là chẵn hay lẻ 
if(n%2 == 0) hoặc if(n&1 == 1)
8. Viết 1 dòng code để lấy bù 2 của n 
n = ~n + 1;
9. Viết 1 dòng code để kiểm tra 2 số a, b có bằng nhau không mà không dùng == 
if(a-b == 0) hoặc if(a&~b == 0) hoặc if(a^b == 0)
10. Viết 1 dòng code để tìm vị trí MSB: 
index = (int)log2(n)+1 hoặc <br>
while(n != 0) <br>
{ <br>

    n = n >> 1; <br>
    ++index; <br>
} <br>
11. Viết 1 dòng code để tìm vị trí LSB: <br>
while(1) <br>
{<br>
    if((n & 1) == 0) <br>
    { <br>
        return index; <br>
    } <br>
    n = n >> 1; <br>
    index++; <br>
} hoặc <br>
index = n & (-n); <br>
12. Viết 1 dòng code để tắt bit 1 ở ngoài cùng bên phải của n <br>
n &= ~(1 << (n & (-n))); <br>
x = x & (x - 1); <br>
13. Viết 1 dòng code để cô lập bit phải nhất: <br>
n & (-n); <br>
14. Viết 1 dòng code để kiểm tra n có phải bội của 8 không? <br>
if(n % 8 == 0) hoặc if(n & 0x7 == 0) <br>
15. Đoạn mã sau có vấn đề gì không? <br>
void myfunction(char *q){ <br>
memcpy(q, "hello", 5); <br>
} <br>

int main(void){ <br>
char* p; <br>
myfunction(p); <br>
return 0; <br>
} <br>
con trỏ p được tạo ra nhưng không được gán, có thể trỏ đến giá trị rác. <br>
16. Hàm hoạt động ra sao? Các biến được cấp phát ở đâu? <br>
int a; <br>
char *b;<br>
const char c[20] = "I am a string";<br>

void func(char d, int c_param, char *f) {<br>
int g = 0;<br>
static int h = 2;<br>
char *i = NULL;<br>
i = (char *)malloc(20);<br>
if (i != NULL) {<br>
free(i);<br>
}<br>
}<br>
hàm func là 1 hàm void lấy 3 tham số đầu vào char, int và con trỏ trỏ đến char, <br>
hàm khởi tạo biến g = 0, biến static h = 2, con trỏ char i = NULL, sau đó nó cấp phát <br>
1 vùng nhớ với kích thước 20 bytes ở bộ nhớ heap và để con trỏ i trỏ vào <br>
sau đó check nếu i không NULL thì giải phóng vùng nhớ heap. Các biến a, con trỏ char b,<br>
character array c với kích thước 20 bytes là biến global và được chứa trong vùng data, cụ thể <br>
a, b được lưu trong vùng uinitialized data (.bss), h, c được lưu trong vùng initialized data (.data) <br>
d, c, f, g, i được khởi tạo trong stack. <br>
17. a và b được cấp phát và lưu trữ ở đâu? <br>
void main(void) { <br>
char a[4] = "foo"; <br>
char *b = "bar"; <br>
} <br>
a và b đều được cấp phát trong stack<br>
18. Đoạn mã sau có vấn đề gì không? Với RAM = 2000 byte? <br>
void myfunction() { <br>
char *q; <br>
for (int i = 0; i < 1000; i++) { <br>
q = (char *)malloc(8); <br>
if (q != NULL) { <br>
memcpy(q, "hello", 6); <br>
} <br>
} <br>
} <br>
Đoạn mã này sẽ làm tràn RAM do vòng lặp chạy 1000 lần mỗi lần tạo 1 vùng nhớ với 8 byte <br>
19. Đoạn mã sau có vấn đề gì không? Làm sao để in ra "hello"? <br>
void myfunction(char *q) { <br>
q = (char *)malloc(8); <br>
if (q) { <br>
memcpy(q, "hello", 6); <br>
} <br>
} <br>

void main(void) { <br>
char *p = NULL; <br>
myfunction(p);<br>
}<br>
Đoạn này có vấn đề là khi truyền con trỏ p vào hàm myfunction thì vẫn là pass by value, nó sẽ tạo ra 1 con trỏ q ở stack <br>trỏ cùng vị trí với p, sau đó cấp phát 1 vùng nhớ ở heap với 8byte, nhưng khi kết thúc hàm thì không trả về, con trỏ <br>q bị xóa không có gì trỏ đến vùng nhớ tack vừa nãy, nên bị memory leak. Khi kết thúc hàm nên trả lại hàm <br>
char* myfunction(char *q) { <br>
q = (char *)malloc(8); <br>
if (q) { <br>
memcpy(q, "hello", 6); <br>
return q; <br>
} <br>
} <br>

void main(void) { <br>
char *p = NULL; <br>
p = myfunction(p);<br>
}<br>
20. Các biến sau được lưu ở đâu? <br>
int a = 5; <br>
int d; <br>
char b[6] = "hello"; <br>
const int c = 4; <br>

void myfunction(void) <br>
{ <br>
static int g = 5; <br>
const int h = 6; <br>
char i; <br>
} <br>
biến a, b được lưu ở vùng .bss, biến d, g được lưu ở vùng .data, biến c được lưu ở vùng text segment, h và i được lưu ở <br> vùng stack <br>
21. Đoạn mã sau có vấn đề gì không? <br>
void main(void) { <br>
char array[20]; <br>
for (int i = 0; i < 20; i++) { <br>
array[i] = i; <br>
} <br>

int *p = (int *)array; <br>
p++; <br>
p++; <br>
printf("Value at p: 0x%x\n", *p); <br>
} <br>
Đoạn mã sau có vấn đề là con trỏ p là con trỏ đến int, nhưng lại trỏ vào array là  1<br> char, mỗi lần ++p thì p sẽ dịch 1 đoạn là 4 byte. sau mỗi lần đọc giá trị của<br> là sẽ đọc 1 giá trị int 4 byte chứ không phải là 1 byte của char <br>
22. Có vấn đề gì với hàm copy sau? <br>
int copy(char *scr, char *dst, unsigned int size) { <br>
char *s1; <br>
while (size--) { <br>
*s1++ = *scr++; <br>
*dst++ = *s1; <br>
} <br>
return 0; <br>
} <br>
Hàm copy này sử dụng 1 biến trung gian là con trỏ char s1, sử dụng như này có thể <br> gây coredump vì con trỏ không được khởi tạo, sẽ trỏ đến giá trị rác <br>
23. Đoạn mã sau có vấn đề gì không? <br>
 void func(void) { <br>
char *p = malloc(10); <br>
strcpy(p, "Embedded"); <br>
} <br>
Đoạn mã này có vấn đề chưa check nếu malloc failed thì con trỏ p sẽ null, thêm nữa <br> nếu hàm này kết thúc thì sẽ bị memory leak vì chưa giải phóng bộ nhớ heap khi <br> kết thúc hàm. <br>
24. Đoạn mã sau có hợp lệ không? <br>
 void test(void) { <br>
char *str = "Hello"; <br>
str[0] = 'h'; <br>
} <br>
Đoạn mã này không hợp lệ vì con trỏ str đang trỏ đến 1 vùng const, không thay đổi được<br>
25. Các biến a, b, c, d được lưu ở đâu trong bộ nhớ? <br>
int a = 10; <br>
const int b = 5; <br>
static int c = 3; <br>
int func(void) { <br>
int d = 2; <br>
return a + b + c + d; <br>
} <br>
Biến a, c được lưu ở vùng .data, biến b được lưu ở vùng text segment, biến d được <br> lưu ở vùng stack <br>
26. Đoạn mã sau có vấn đề gì? <br>
void recursion(int x) { <br>
int a[100]; <br>
recursion(x + 1); <br>
} <br>
đoạn mã này có vấn đề là không có điều kiện kết thúc vòng lặp, dẫn đến làm cạn bộ <br> nhớ stack <br>
27. Đoạn mã sau có in ra đúng giá trị ban đầu không? Tại sao? <br>
int main(void) { <br>
int a = 0x12345678; <br>
char *p = (char *)&a; <br>
p[0] = 0xAA; <br>
printf("a = 0x%x\n", a); <br>
} <br>
Đoạn mã sau không in ra đúng giá trị ban đầu, do con trỏ p trỏ đến byte cuối của a <br> thay đổi nó <br>
28. Đoạn mã sau có vấn đề gì? <br>
char *getString(void) { <br>
char str[] = "hello"; <br>
return str; <br>
} <br>
int main(void) { <br>
char *s = getString(); <br>
printf("%s\n", s); <br>
} <br>
Đoạn mã có vấn đề ở biến str là biến local sẽ bị hủy sau khi kết thúc gọi hàm, do đó <br> con trỏ char s sẽ trỏ vào vùng rác, gây coredump <br>
29. 1. Kết quả in ra là gì? <br>
2. Nếu bỏ từ khóa static, kết quả có khác không? <br>
3. Biến count được lưu ở vùng nhớ nào? <br>
void counter(void) { <br>
static int count = 0; <br>
count++; <br>
printf("%d ", count); <br>
} <br>

int main(void) { <br>
for (int i = 0; i < 3; i++) <br>
counter(); <br>
return 0; <br>
} <br>
Kết quả in ra là 1 2 3. Nếu bỏ từ khóa static thì kết quả là 1 1 1. Biến count được <br> lưu ở vùng .data. <br>
30. 1. Code này có biên dịch được không? <br>
2. Nếu không, compiler báo lỗi gì? Tại sao? <br>
int main(void) { <br>
register int x = 5; <br>
printf("%d\n", x); <br>
printf("%p\n", &x); <br>
return 0; <br>
}  <br>
Đoạn này không biên dịch được. Compiler báo lỗi "error: address of register variable ‘x’ requested"<br> Do không thể in được địa chỉ của biến register<br>
31. sizeof(struct ab) và sizeof(struct ba) là bao nhiêu ? <br>
struct <br>
{ <br>
int a; <br>
char b; <br>
} ab; <br>

#pragma pack(push, 1) <br>
struct <br>
{ <br>
char a; <br>
int b; <br>
} ba; <br>
#pragma pack(pop) <br>
sizeof(struct ab) là 5, sizeof(struct ba) là 8 <br>
32. sizeof(mystruct) sẽ in ra gì? <br>
typedef struct { <br>
char x; <br>
int y; <br>
} mystruct; <br>
sizeof(mystruct) sẽ in ra 8 <br>
33. sizeof(struct A) là bao nhiêu trên hệ thống 32-bit? <br>
struct A { <br>
char a; <br>
int b; <br>
short c; <br>
}; <br>
đáp án là 12 <br>
34. Ảnh hưởng của #pragma pack(1) là gì? Kết quả sizeof(struct B) là bao nhiêu trên hệ thống 32-bit? <br>
#pragma pack(push, 1) <br>
struct B { <br>
char a; <br>
int b; <br>
short c; <br>
}; <br>
#pragma pack(pop) <br>
pragma pack(1) sẽ khiến cho alignment chỉ còn là 1 cho struct, kết quả là 7 <br>
35. Tính sizeof(struct Outer) trên hệ thống 32-bit <br>
struct Inner { <br>
char c; <br>
int d; <br>
}; <br>

struct Outer { <br>
int a; <br>
struct Inner in; <br>
char e[3]; <br>
}; <br>
Đáp án là 16 <br>
36. Trong đoạn mã sau, ab.b có giá trị là bao nhiêu? <br>
union data { <br>
int a; <br>
char b; <br>
} ab; <br>

ab.a = 64; <br>
ab.a = 2500; // 0x09C4 <br>
ab.b có giá trị là 0xc4<br>
37. sizeof(struct Test) là bao nhiêu trên hệ thống 32-bit? <br>
union Data { <br>
int i; <br>
char c[4]; <br>
}; <br>

struct Test { <br>
char flag; <br>
union Data data; <br>
}; <br>
kích thước là 8 <br>
38. Kết quả khác nhau như thế nào giữa little-endian và big-endian? <br>
union U { <br>
int val; <br>
char byte[4]; <br>
}; <br>

int main(void) { <br>
union U u; <br>
u.val = 0x12345678; <br>
printf("%x %x %x %x\n", u.byte[0], u.byte[1], u.byte[2], u.byte[3]); <br>
} <br>
little endian thì kết quả sẽ là 78 56 34 12, big endian thì kết quả là 12 34 56 78 <br>

39. sizeof(struct Flags) là bao nhiêu? <br>
struct Flags { <br>
unsigned int a : 1; <br>
unsigned int b : 3; <br>
unsigned int c : 4; <br>
}; <br>
sizeof(struct Flag) là 4 bytes <br>
40. 1. Giá trị flag, mode, value sẽ in ra bao nhiêu (giả sử hệ thống little-endian)? <br>
2. Tại sao giá trị thay đổi khi chạy trên big-endian? <br>
3. Giải thích cách compiler ánh xạ bit field vào raw. <br>
union Data { <br>
struct { <br>
unsigned int flag : 3; <br>
unsigned int mode : 5; <br>
unsigned int value : 8; <br>
} info; <br>
unsigned short raw; <br>
}; <br>

int main(void) { <br>
union Data d; <br>
d.raw = 0xABCD; <br>
printf("flag=%u, mode=%u, value=%u\n", d.info.flag, d.info.mode, d.info.value); <br>
} <br>
flag = 5, mode = 25, value = 171 <br>
big-endian là sẽ đảo ngược lại trọng số các bit <br>
raw sẽ chia thành 16 bit ứng với 2 byte của unsigned int, ABCD sẽ ứng với từng bit <br>
41. 1. sizeof(struct Packet) là bao nhiêu trên 32-bit? <br>
2. Giải thích tại sao sizeof không phải luôn bằng 2? <br>
3. Nếu ta gán data.raw = 0xAB, giá trị của id, type, err lần lượt là gì? <br>
struct Packet { <br>
unsigned char header; <br>
union { <br>
struct { <br>
unsigned int id : 4; <br>
unsigned int type : 3; <br>
unsigned int err : 1; <br>
} bits; <br>
unsigned char raw; <br>
} data; <br>
}; <br>
1. sizeof(struct packet) là 8 byte trên 32-bit. <br>
2. bitfields có kiểu unsigned int -> compiler có thể yêu cầu căn theo boundary của <br> unsigned int (4 bytes). Dù bitfield chỉ chiếm 1 byte logic compiler vẫn chừa 4 bytes để đảm bảo alignment chuẩn kiến trúc. <br> Thêm vào đó, union phải đủ lớn để chưa bất kỳ member lớn nhất, nên chiếm 4 bytes. <br>
3. giá trị của id, type, err lần lượt là 11, 1, 1 <br>

42. 1. sizeof(union Config) là bao nhiêu? <br>
2. Tại sao cả hai struct đều có cùng vùng nhớ? <br>
3. Nếu gán security.key = 0x7F, giá trị normal.mode có thay đổi không? <br>
union Config { <br>
struct { <br>
unsigned int enable : 1; <br>
unsigned int speed : 2; <br>
unsigned int mode : 3; <br>
} normal; <br>

struct { <br>
unsigned int secure : 1; <br>
unsigned int key : 7; <br>
} security; <br>
}; <br>
1. sizeof(union Config) có giá trị là 4 byte, do alignment theo unsigned int <br>
2. cả 2 struct có cùng vùng nhớ vì đều là member của union, union đảm bảo các thành viên <br> cùng bắt đầu tại cùng 1 vùng nhớ vật lý <br>
3. Nếu gán security.key = 0x7F, giá trị normal.mode = 7 <br>

43. 1. In ra kết quả gì (với little-endian)? <br>
2. Giải thích tại sao việc truy cập ctrl.bits và ctrl.reg lại ảnh hưởng trực tiếp nhau? <br>
3. Nếu muốn MODE chiếm bit 4–5 thay vì 1–2, sửa khai báo thế nào? <br>
typedef union { <br>
struct { <br>
unsigned int EN : 1; <br>
unsigned int MODE : 2; <br>
unsigned int RSV : 1; <br>
unsigned int CLK : 4; <br>
} bits; <br>
unsigned char reg; <br>
} CTRL_REG; <br>

int main(void){ <br>
CTRL_REG ctrl = { .reg = 0xB2 }; <br>
printf("EN=%u, MODE=%u, CLK=%u\n", ctrl.bits.EN, ctrl.bits.MODE, ctrl.bits.CLK); <br>
} <br> 
1. In ra kết quả là EN = 0, MODE = 1, CLK = 11 <br>
2. Vì do đều là cùng member của union nên đều bắt đầu chung 1 vùng nhớ <br>
3. struct { <br>
unsigned int EN: 4; <br>
unsigned int MODE: 2; <br>
unsigned int RSV: 1; <br>
unsigned int CLK: 4; <br>
} <br>

44. 1. sizeof(union Frame) là bao nhiêu? <br>
2. Nếu bytes.low = 0xAA và bytes.high = 0xBB, giá trị của info.len, info.type, info.crc là gì? <br>
3. Giải thích tại sao giá trị có thể khác nhau giữa compiler (GCC vs ARMCC)? <br>
union Frame { <br>
struct { <br>
unsigned short len : 10; <br>
unsigned short type : 3; <br>
unsigned short crc : 3; <br>
} info; <br>

struct { <br>
unsigned char low; <br>
unsigned char high; <br>
} bytes; <br>
}; <br>
1. sizeof(union Frame) là 16 <br>
2. len = 938, type = 6, crc = 5 <br>
3. Các compiler quyết định riêng: <br>
GCC (trên little-endian) → bit 0 là LSB của byte đầu tiên. <br>
ARMCC / Keil → bit-field có thể được đánh số từ MSB của byte đầu tiên. <br>
→ Nghĩa là thứ tự bit trong unsigned short có thể đảo ngược giữa compiler. <br>