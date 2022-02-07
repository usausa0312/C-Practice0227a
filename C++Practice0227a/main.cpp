#include <iostream>
#include <fstream>
#include <string>

//今回は元からプロジェクトにtxtが存在していないとエラー吐きます

int main()
{
    //csv とか　txt等
    std::string fileName = "csv/test.txt";

    {//出力
        //ofstream読み取りモード
        std::ofstream ofs(fileName, std::ios::out);
        if (!ofs)
        {
            std::cout << "ファイルが開けませんでした。" << std::endl;
            std::cin.get();
            return 0;
        }
        ofs << "書 き ま し た" << std::endl;
        int Data = 123;
        ofs << Data 
            <<"," //横のセルに移動 txtならただの,
            << Data << std::endl;
        ofs << "書き込み終了" << std::endl;

    }

    {//入力
        std::ifstream ifs(fileName);
        if (!ifs)
        {
            std::cout << "ファイルが開けませんでした。" << std::endl;
            std::cin.get();
            return 0;
        }
        std::string data;

        //ファイルからstringにデータ格納
        std::getline(ifs, data);//getlineは改行まで

        std::cout << data << std::endl;
    }

    { //入出力
        std::string data;
        std::fstream fs(fileName);
        if (!fs)
        {
            std::cout << "ファイルが開けませんでした。" << std::endl;
            std::cin.get();
            return 0;
        }
        std::string buf;
        std::string::size_type match;
        while (1)
        {
            std::getline(fs, buf);
            if (fs.eof()) //ファイル終端判定
                break;

            match = buf.find("終了");
            if (match != std::string::npos)
                buf.replace(match, 4, "二回目"); //4は"終了"の文字数　*全角なので+2 半角だとそのままの文字数でおk
            data += buf + "\n";
        }

        //////////
        //読み込みをするときにファイルの末尾を確認してそこまで読み込む処理を書かないといけないが、
        //一度ファイル終端まで達すると、ファイル位置移動関数が効かなるので
        //eofフラグを切る
        fs.clear();              //eofフラグをクリア
        fs.seekp(std::ios::beg); //ファイル位置を先頭にセット

        fs << data; //書き込み
        //////////
        std::cout << data;
    }

    std::cin.get();
}