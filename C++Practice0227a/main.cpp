#include <iostream>
#include <fstream>
#include <string>

//����͌�����v���W�F�N�g��txt�����݂��Ă��Ȃ��ƃG���[�f���܂�

int main()
{
    //csv �Ƃ��@txt��
    std::string fileName = "csv/test.txt";

    {//�o��
        //ofstream�ǂݎ�胂�[�h
        std::ofstream ofs(fileName, std::ios::out);
        if (!ofs)
        {
            std::cout << "�t�@�C�����J���܂���ł����B" << std::endl;
            std::cin.get();
            return 0;
        }
        ofs << "�� �� �� �� ��" << std::endl;
        int Data = 123;
        ofs << Data 
            <<"," //���̃Z���Ɉړ� txt�Ȃ炽����,
            << Data << std::endl;
        ofs << "�������ݏI��" << std::endl;

    }

    {//����
        std::ifstream ifs(fileName);
        if (!ifs)
        {
            std::cout << "�t�@�C�����J���܂���ł����B" << std::endl;
            std::cin.get();
            return 0;
        }
        std::string data;

        //�t�@�C������string�Ƀf�[�^�i�[
        std::getline(ifs, data);//getline�͉��s�܂�

        std::cout << data << std::endl;
    }

    { //���o��
        std::string data;
        std::fstream fs(fileName);
        if (!fs)
        {
            std::cout << "�t�@�C�����J���܂���ł����B" << std::endl;
            std::cin.get();
            return 0;
        }
        std::string buf;
        std::string::size_type match;
        while (1)
        {
            std::getline(fs, buf);
            if (fs.eof()) //�t�@�C���I�[����
                break;

            match = buf.find("�I��");
            if (match != std::string::npos)
                buf.replace(match, 4, "����"); //4��"�I��"�̕������@*�S�p�Ȃ̂�+2 ���p���Ƃ��̂܂܂̕������ł�k
            data += buf + "\n";
        }

        //////////
        //�ǂݍ��݂�����Ƃ��Ƀt�@�C���̖������m�F���Ă����܂œǂݍ��ޏ����������Ȃ��Ƃ����Ȃ����A
        //��x�t�@�C���I�[�܂ŒB����ƁA�t�@�C���ʒu�ړ��֐��������Ȃ�̂�
        //eof�t���O��؂�
        fs.clear();              //eof�t���O���N���A
        fs.seekp(std::ios::beg); //�t�@�C���ʒu��擪�ɃZ�b�g

        fs << data; //��������
        //////////
        std::cout << data;
    }

    std::cin.get();
}