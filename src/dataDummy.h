#pragma once

class dataDummy{
  public:
    dataDummy(std::string i_msg, int i_vct): msg(i_msg), content(i_vct){}
    std::string getMessage(){return msg;}
    void printContent(){
      std::cout << "Contents ";
      std::cout << content << std::endl;
    }
  private:
    std::string msg;
    int content;
};
