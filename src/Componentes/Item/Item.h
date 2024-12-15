#ifndef SUPPORT_TP_ITEM_H
#define SUPPORT_TP_ITEM_H

#include <iostream>

class Item {
private:
    std::string nome;
    int vidaUtil;
public:
  Item(std::string nome, int vidaUtil);

  std::string getNome() const;

  void setNome(std::string nome);

  int getVidaUtil() const;

  void setVidaUtil(int vidaUtil);
};


#endif //SUPPORT_TP_ITEM_H
