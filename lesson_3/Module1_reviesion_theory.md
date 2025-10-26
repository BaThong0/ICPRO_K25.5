1. Làm thế nào để bật 1 bit cụ thể trong 1 biến? <br>
- Dùng toán tử OR với giá trị 1 dịch trái đến vị trí đó. <br>
2. Làm thế nào để đảo 1 bit cụ thể trong 1 biến? <br>
- Dùng toán tử XOR với giá trị 1 dịch trái đến vị trí đó <br>
3. Làm thể nào để kiểm tra 1 bit cụ thể đã được bật hay chưa? <br>
- Sử dụng toán tử AND với giá trị 1 dịch trái đến vị trí đó <br>
4. Làm thể nào để hoán đổi 2 số mà không cần dùng biến thử 3? <br>
- Dùng XOR swap hoặc a = a +b, b = a - b, a = a - b; <br>
5. Làm thế nào để kiểm tra 1 số có phải là lũy thừa của 2 hay không? <br>
- Kiểm tra n&(n-1) == 0 hoặc n % 2 == 0 <br>
6. Làm thế nào để đếm số bit 1 trong biểu diễn nhị phân của 1 số? <br>
- Dùng vòng lặp hoặc __builtin_popcount(); <br>
7. Làm thế nào để kiểm tra là 1 số là chẵn hay lẻ? <br>
- n % 2 == 0 hoặc (n&1) == 1 <br>
8. Làm thế nào tìm bù 2 của 1 số nhị phân? <br>
- đảo bit bằng NOT rồi + 1 <br>
9. Làm thế nào để kiểm tra 2 số có bằng nhau không mà không mà không <br>
dùng toán tử so sánh <br>
- Dùng XOR: if((a^b) == 0), hoặc if((a - b) == 0) <br>
10. Tìm bit có trọng số lớn nhất? <br>
- Dùng log2(n) hoặc vòng lặp dịch bit <br>
11. Tìm bit có trọng số nhỏ nhất <br>
- Dùng n & (-n) hoặc vòng lặp dịch bit <br>
12. Làm thế nào để tắt bit 1 ở ngoài cùng bên phải ? <br>
- x = x & (x - 1) <br>
13. Làm thế nào để cô lập bit 1 ở ngoài cùng bên phải? <br>
- x & (-x) <br>
14. làm thế nào để kiếm tra 1 số có phải là bội của 8 hay không? <br>
- if(n%8 ==0) hoặc (n & 0x7) == 0 <br>
15. Có những phân đoạn vùng nhớ nào? <br>
- text segment: chứa code hoặc các biến chỉ đọc <br>
- .data: chứa các biến global, static đã được khởi tạo khác 0 <br>
- .bss: chứa các biến global, static chưa được khởi tạo <br>
- heap: chứa các dữ liệu được cấp phát động (malloc, alloc, calloc, new) <br>
- stack: chứa các biến, hàm local <br>
16. Tại sao phải chia vùng .data và .bss ? <br>
Để quản lý dữ liệu hiệu quả hơn. .data sẽ copy dữ liệu ở trên ROM để gán vào RAM, còn .bss sẽ gán bằng 0 <br>
khi CPU boot lên tránh việc lưu trữ rất nhiều biến 0 ở ROM gây lãng phí bộ nhớ. Giảm kích thước file bin <br>
17. Biến toàn cục không khởi tạo nằm ở đâu? <br>
- Nằm trong vùng .bss <br>
18. 2 biến global có cùng giá trị khởi tạo là 0 và 10, tại sao chúng không cùng 1 vùng nhớ? <br>
- Biến có giá trị 10 sẽ nằm ở vùng .data, biến có giá trị bằng 0 sẽ nằm ở vùng .bss <br>
19. Khi chương trình gọi một hàm lồng nhau nhiều lần (đệ quy), vùng nhớ nào bị ảnh hưởng nhiều nhất? <br>
- Vùng nhớ stack, có thể bị stackoverflow <br>
20. Tại sao biến const thường được đặt trong vùng .rodata thay vì .data? <br>
- Vì vùng này nằm ở ROM, dũ liệu chỉ đọc không được ghi thay vì RAM <br>
21. Nếu bạn muốn dữ liệu tồn tại suốt vòng đời chương trình, bạn nên đặt nó ở vùng nhớ nào? <br>
- .data hoặc .bss <br>
22. Tại sao vùng .bss không chiếm nhiều dung lượng trong file .bin, nhưng lại chiếm RAM khi chạy? <br>
- Do vùng nhớ .bss chỉ lưu thông tin kích thước, không chứa dữ liệu thực, điều này nằm tiết kiệm tài <br>
nguyên trên RAM, khi khởi động không tốn công copy giá trị từ ROM vào RAM. Thêm nữa tiết kiệm cho file bin <br>
23. Điều gì xảy ra với Stack khi hàm kết thúc, nhưng biến static trong hàm đó vẫn được giữ giá trị? <br>
- Stack sẽ giải phóng hàm đó nhưng static lại là biến dược tạo và lưu ở trong vùng data cho nên không bị giải <br> phòng khi stack pop <br>
24. Lỗi memory leak xảy ra khi nào? Tại sao? Cách debug ? <br>
- Xảy ra khi cấp phát động vùng nhớ mà quên không giải phòng. Cách debug là dùng valgrind <br>
25. Lỗi stack overflow xảy ra khi nào? cách debug ? <br>
- Xảy ra khi chương trình sử dụng quá nhiều bộ nhớ stack, do đệ quy vô hạn hoặc khai báo mảng lớn. Dùng gdb backtrack <br>
26. Lỗi segmentation fault xảy ra khi nào? Tại sao? Cách debug? <br>
- Xảy ra khi truy cập vùng nhớ không hợp lệ (null ptr, out of range). Cách debug dùng gdb xem backtrace <br>
27. Lỗi Stack Smashing là gì? Cách compiler phát hiện bằng cơ chế Canary <br>
Khi chương trình ghi quá giới hạn của 1 biến cục bộ (local variable) được cấp phát trên stack, làm ghi đè (overwrite) lên các dữ liệu khác <br>
trong stack như: <br>
- các biến cục bộ khác <br>
- con trỏ khung stack (frame pointer) <br>
- và đặc biệt là địa chỉ trả về (return address) của hàm <br>
Compiler phát hiện bằng cơ thế Canary bằng cách đặt 1 biến canary vào giữa local variable và return address, nếu viết vượt quá biến này thì sẽ raise <br>
cờ cảnh báo stack smashing <br>
28. Lỗi Heap Corruption là gì? Cách phát hiện bằng AddressSanitizer. <br>
- Lỗi này xảy ra khi chương trình làm hỏng vùng nhớ cấp phát động, thường do: <br>
- Ghi tràn (overflow) - ghi quá giới hạn của vùng được malloc() <br>
- Ghi trước (underflow) - ghi vào vùng trước con trỏ được cấp <br>
- Giải phóng sai (double free) - free() cùng 1 con trỏ 2 lần <br>
- Use-after-free - Dùng con trỏ sau khi free() <br>
- Free nhầm (invalid free) - free() con trỏ không do malloc() cấp <br>
- Phát hiện bằng AddressSanitizer bằng cách bật gcc -fsanitize=address -g main.c -o main <br>
- AddressSanitizer sẽ báo heap-buffer-overflow, chỉ ra địa chỉ, kích thước ghi, hàm, dòng code <br>
29. Lỗi Dangling Pointer là gì? Tại sao nguy hiểm? Cách khắc phục. <br>
- Là một con trỏ trỏ đến vùng nhớ không hợp lệ - tức là vùng nhớ đó đã bị giải phóng hoặc ra khỏi phạm vi sử dụng <br>
- Hậu quả gây ra: <br>
+ Undefindè behavior: Không thể đoán kết quả - có thể crash, in sai hoặc chạy ổn "ngẫu nhiên" <br>
+ Khó debug: Vì lỗi thường xảy ra sau một thời gian khi vùng nhớ bị tái sử dụng  <br>
+ Bảo mật nghiêm trọng: Hacker có thể khai thác dangling pointer để ghi dữ liệu vào vùng nhớ quan trọng (heap/stack corruption) <br>
+ Không phát hiện bằng compiler thường: Compiler, C/C++ không có runtime check, nên bạn chỉ phát hiện bằng tool như ASan, Valgrind <br>
- Cách khắc phuc: <br>
+ Sau khi free(), luôn gán con trỏ về NULL <br>
+ Không trả về địa chỉ của biến cục bộ <br>
+ Giữ ownership rõ ràng <br>
+ Dùng smart pointer <br>
30. Khi nào nên dùng AddressSanitizer thay vì Valgrind để debug lỗi bộ nhớ? <br>
Nếu bạn cần debug runtime thực tế (ví dụ chương trình chạy nhiều thread, nhiều IO, nhiều dữ liệu) → ASan nhanh hơn rất nhiều. <br>
Nếu bạn cần phân tích chi tiết, cực kỳ chính xác → Valgrind. <br>
31. Lỗi Wild Pointer là gì? <br>
- Khi con trỏ không được gán giá trị hợp lệ. Cần khởi tạo NULL <br>
32. Các lớp lưu trữ (storage classes) là gì? <br>
Storage class (lớp lưu trữ) xác định: <br>
- Vùng nhớ của biến (RAM, Flash, stack, v.v.) <br>
- Thời gian tồn tại (lifetime) <br>
- Phạm vi truy cập (scope) <br>
- Liên kết (linkage) – có thể dùng ở file khác không <br>
33. Từ khóa auto dùng để làm gì? Khi nào thì dùng? <br>
- từ khóa mặc định cho biến cụ bộ trong hàm <br>
- biến được cấp phát tự động trên stack khi hàm được gọi <br>
- khi hàm kết thúc, biến được giải phóng tự động (hết phạm vi tồn tại) <br>
- Do đó, trong C, auto hầu như không bao giờ được viết ra, vì mặc định biến cục bộ là "auto storage" <br>
34. Từ khóa static dùng để làm gì? Khi nào thì dùng? <br>
- Từ khóa static được dùng để thay đổi phạm vi truy cập, thời gian tồn tại và liên kết của file. <br> 
- Nếu là biến thì biến được lưu ở vùng .data, phạm vi truy cập là toàn bộ trong cục bộ file và ẩn khỏi file khác, thời gian tồn tại là suốt chương trình <br>
- Tương tự với hàm cũng là để dùng trong cục bộ file và ẩn khỏi file khác <br>
35. Từ khóa extern dùng để làm gì? Khi nào thì dùng? <br>
- Dùng để thay đổi phạm vi truy cập là ở toàn bộ các file, thời gian tồn tại là toàn chương trình, vị trí lưu là ở vùng data segment <br>
- Khi cần sử dụng biến hoặc hàm từ 1 file khác mà ở file đó đã đinh nghĩa rồi <br>
36. Từ khóa register dùng để làm gì? Khi nào thì dùng? <br>
Từ khóa register gợi ý cho compiler rằng biến này được lưu trong thanh ghi CPU (register) thay vì trong RAM để tăng tốc độ truy cập <br>
37. Từ khóa volatile dùng để làm gì? Khi nào thì dùng? <br>
- Từ khóa volatile để tránh cho compiler làm mất đi biến trong quá trình tối ưu hóa mã nguồn, biến này có thể thay đổi bất kỳ lúc nào mà không phải do. <br> chương trình hiện tại gây ra. Cần dùng khi dùng với các địa chỉ thanh ghi, thứ bị thay đổi <br> khi có sự kiện ngoài làm thay đổi như ngắt <br>
38. Khác nhau giữa struct và array? <br>
- struct để lưu các phần tử khác kiểu dữ liệu, là 1 nguyên mẫu biến. array lưu các phần tử cùng kiểu <br>
39. Kích thước struct được tính như thế nào? <br>
- được tính bằng kích thước phần tử + padding (theo alignment) <br>
40. Căn chỉnh bộ nhớ trong struct hoạt động như nào? <br>
- Mỗi kiểu dữ liệu thường được yêu cầu đặt tại địa chỉ chia hết cho kích thước của nó <br>
41. Padding là gì trong struct? Làm sao tránh padding? <br>
- Padding là các byte trống (không sử dụng) mà compiler tự động thêm vào trong struct để đảm bảo căn chỉnh bộ nhớ (memory alignment) cho từng trường <br>
- Tránh padding dùng #pragma pack(1) hoặc __attribute__((packed))
42. Có thể gán trực tiếp giữa 2 struct cùng kiểu không? <br>
- Có thể bằng cách copy byte-to-byte <br>
43. struct có thể so sánh bằng toán tử == không? <br>
- Không trong C chỉ có thể só sánh từng trường <br>
44. Struct có thể dùng làm tham số hàm không? <br>
- Có nhưng thường dùng con trỏ để tiết kiệm bộ nhớ <br>
45. #pragma pack(1) có ý nghĩa gì? <br>
- nói cho compiler biết chỉ padding 1 byte cho struct sau <br>
46. Khi truyền struct vào hàm, có thể bị padding sai khi giao tiếp giữa vi điều khiển khác nhau không? <br>
- Có. Cần __attribute__((packed)) hoặc cấu hình #pragma pack. <br>
47. Union là gì? <br>
- Kiểu dữ liệu đặc biệt cho phép nhiều thành viên chia sẻ cùng một vùng nhớ. <br>
48. Kích thước của union bằng bao nhiêu ? <br>
- Bằng kích thước của thành viên lớn nhất <br>
49. Union dùng khi nào? <br>
- Khi cần tiết kiệm bộ nhớ, ví dụ dữ liệu có thể ở nhiều dạng khác nhau nhưng chỉ dùng một tại một thời điểm. <br>
50. Nếu ghi vào 1 thành viên union rồi đọc thành viên khác thì sao? <br>
- Vẫn có thể đọc được nhưng sẽ đọc theo kiểu byte mà biến đó đang được định nghĩa, có thể nói là không xác định <br>
51. Có thể khởi tạo nhiều thành viên của union cùng lúc không? <br>
- Không, chỉ có 1 thành viên tại 1 thời điểm <br>
52. Union có thể chứa struct không? <br>
- Có, và ngược lại <br>
53. Union thường dùng trong embedded để làm gì? <br>
- Dùng để map bit/byte của thanh ghi, chuyển đổi giữa các kiểu dữ liệu khác nhau, tiết kiệm bộ nhớ, giải mã protocol <br>
54. Enum là gì? <br>
- Là 1 kiểu dữ liệu do người dùng định nghĩa dùng để đặt tên có nghĩa cho các giá trị hằng số nguyên (int) <br>
55. Mặc định giá trị đầu tiên của enum là gì? <br>
- số 0 <br>
56. Enum có thể gán giá trị cụ thể cho phần tử không? <br>
- Có <br>
57. Giá trị của phần tử tiếp theo nếu không chỉ định? <br>
- tự động tăng 1 từ giá trị trước <br>
58. Tại sao nên dùng enum thay vì #define? <br>
- vì enum có kiểu dữ liệu, dễ debug, nhóm logic, gọi ý switch-case,... <br>
59. Enum có thể âm không? <br>
- Có, vì enum là kiểu signed int <br>
