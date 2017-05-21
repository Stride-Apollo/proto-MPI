#pragma once

class DataDummy{
  public:
    DataDummy(std::string i_msg, int i_vct): msg(i_msg), content(i_vct){}
    std::string getMessage(){return msg;}
    void printContent(){
      std::cout << "Contents ";
      std::cout << content << std::endl;
    }
  private:
    std::string msg;
    int content;
};

class TravelData{
  public:
    void print(){
      std::cout << "Amount of people sent: " << m_amount << " people for " << m_days << " days.\n";
      std::cout << "Destination district: " << m_destination_district << std::endl;
      std::cout << "Destination facility: " << m_destination_facility << std::endl;
    };
    TravelData(uint amount, uint days, std::string destination_district, std::string destination_facility) : m_amount(amount), m_days(days), m_destination_district(destination_district), m_destination_facility(destination_facility){}

  private:
    uint m_amount;
    uint m_days;
    std::string m_destination_district;
    std::string m_destination_facility;
};
