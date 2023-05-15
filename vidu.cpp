
package java57_vidu;
import java.text.DateFormat;
import java.text.NumberFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;
public
class Taixiu
{
public
    static void main(String[] args)
    {
        double taikhoannguoichoi = 5000000;
        Scanner sc = new Scanner(System.in);
        Locale lc = new Locale("vi", "VN");
        // NumberFofmat numf= NUmberFormat.getCurrencyInstance()lc;
        // NumberFormat numf = NumberFormat.getInstance(lc);
        NumberFormat numf = NumberFormat.getCurrencyInstance(lc);
        int luachon = 0;
        do
        {
            System.out.println("---Mời bạn chọn---");
            System.out.println("1.Để tiếp tục.");
            System.out.println("2.Để hướng dẫn chơi game.");
            System.out.println("3.Để tiếp thoát.");

            luachon = sc.nextInt();
            if (luachon == 1)
            {
                System.out.println("Bắt đầu chơi: ");
                // đặt cược
                System.out.println("***** Tài khoản của bạn: " + numf.format(taikhoannguoichoi) + " Bạn muốn cược bao nhiêu:");
                double datcuoc = 0;
                DateFormat df = new SimpleDateFormat();
                df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

                do
                {
                    System.out.println("*****Đặt cược (0<Số tiền cược<= " + taikhoannguoichoi + ":");
                    datcuoc = sc.nextDouble();
                } while (datcuoc <= 0 || datcuoc > taikhoannguoichoi);
                int luachontaixiu = 0;
                do
                {
                    System.out.println("*****Chọn 1=tài hoặc Chọn 2=xỉu");
                    luachontaixiu = sc.nextInt();
                } while (luachontaixiu != 1 && luachontaixiu != 2);
                // Tung xúc xắc
                Random xucxac1 = new Random();
                Random xucxac2 = new Random();
                Random xucxac3 = new Random();

                int giatri1 = xucxac1.nextInt(5) + 1;
                int giatri2 = xucxac2.nextInt(5) + 1;
                int giatri3 = xucxac3.nextInt(5) + 1;
                int tong = giatri1 + giatri2 + giatri3;

                // Tính toán kết quả

                System.out.println("Kết quả: " + giatri1 + "  " + giatri2 + "  " + giatri3);

                if (tong == 3 || tong == 18)
                {
                    System.out.println("*****Tổng là: " + tong + "=>Nhà cái ăn hết,Bạn đã thua!Chúc bạn may mắn lần sau.Còn thở còn gỡ");
                    taikhoannguoichoi -= datcuoc;
                    System.out.println("*****Tổng la: " + tong + "=>Nhà cái ăn hết >Bạn đã thua.");
                    System.out.println("***** Tài khoản của bạn là: " + taikhoannguoichoi);
                }
                else if (tong >= 4 && tong <= 10)
                {
                    System.out.println("***** Tổng là: " + tong + "=> Xỉu.");
                    if (luachontaixiu == 2)
                    {
                        System.out.println("***** Bạn đã thắng cược.");
                        taikhoannguoichoi += datcuoc;
                        System.out.println("***** Tài khoản của bạn là: " + taikhoannguoichoi);
                    }
                    else
                    {
                        System.out.println("***** Bạn đã thua cược.");
                        taikhoannguoichoi -= datcuoc;
                        System.out.println("***** Tài khoản của banj là: " + taikhoannguoichoi);
                    }
                }
                else
                {
                    System.out.println("*****Tổng là: " + tong + " => Tài.");
                    if (luachontaixiu == 1)
                    {
                        System.out.println("***** Bạn đã thắng cược.");
                        taikhoannguoichoi += datcuoc;
                        System.out.println("***** Tài khoản của bạn là: " + taikhoannguoichoi);
                    }
                    else
                    {
                        System.out.println("***** Bạn đã thua cược.");
                        taikhoannguoichoi -= datcuoc;
                        System.out.println("***** Tài khoản của bạn là: " + taikhoannguoichoi);
                    }
                }
            }
            if (luachon == 2)
            {
                System.out.println("Mỗi người chơi sẽ có một tài khoản .Người chơi có quyền đặt ít hơn hoặc bằng sô tiền đang có.");
                System.out.println("Nếu tiền bằng 0=>Không thể chơi game");
                System.out.println("Luật chơi như sau:");
                System.out.println("Có 3 con xúc xắc.Mỗi viên xúa xắc có 6 mặt từ 1 đến 6.");
                System.out.println("Mỗi lần gieo xúc xắc sẽ ra 1 kết quả.Kết qủa =giá trị xx1 +giá trị xx2+giá trị xx3");
                System.out.println("1.Nếu tông số chấm 3 con xúc xẵc trong 1 lần gieo =3 hoặc =18=>Nhà cái ăn hết, người chơi thua.");
                System.out.println("2.Nếu tổng số chấm 3 con xúc xắc trong 1 làn gieo (4->10) <->Xỉu =>Nếu người chơi đặt xỉu thì người chơi thắng ,ngược lại thua.");
                System.out.println("3.Nếu tổng số chấm 3 con xúc xắc trong 1 lần gieo (11-17) <->Tài =>Nếu người chơi đặt tài thì người chơi thắng , ngược lại thua. ");
                System.out.println("Chúc bạn chơi game vui vẻ!");
            }
            System.out.println("Bây giờ là:");
            Date d = new Date(System.currentTimeMillis());
            System.out.println(d);
        } while (luachon == 1 || luachon == 2);
    }
}
