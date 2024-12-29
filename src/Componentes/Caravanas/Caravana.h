#ifndef SUPPORT_TP_CARAVANA_H
#define SUPPORT_TP_CARAVANA_H

#include <string>
#include <sstream>
#include <iostream>

class Mapa;

class Caravana {
public:
    Caravana(int row, int col, char id, int nPessoas,
             int maxPessoas, int maxAgua,
             int maxJogadasPTurno,
             int maxMercadoria,
             Mapa *onde,
             int turnosParaDesaparecer);

    virtual ~Caravana() = default;

    //PESSOAS GETTERS E SETTERS

    int getNPessoas() const;

    int getmaxPessoas() const;

    void adicionaPessoas(int pessoasAAdicionar);

    int setSecuredPessoas(int pessoas);

    void removePessoas(int pessoasARemover);

    void setNPessoas(int numeroPessoas);

    //AGUA GETTERS E SETTERS

    int getnivelAgua() const;

    int getMaxAgua() const;

    void removerAgua(int aguaARemover);

    void setNivelAgua(int nivelAgua);

    void abastecerAgua();

    void addAgua(int agua);

    virtual void perdeAgua() = 0;

    //ID GETTERS E SETTERS

    char getID() const;

    void setID(char newID);

    //MERCADORIA GETTERS E SETTERS

    int getMercadoria() const;

    int getMaxMercadoria() const;

    void adicionaMercadoria(int mercadoriaAAdicionar);

    void removeMercadoria(int mercadoriaARemover);

    int setSecuredMercadoria(int mercadoria);

    void setMercadoria(int novaMercadoria);

    //MOVIMENTOS GETTERS E SETTERS

    virtual bool move(const std::string &direction);

    void moveManual();

    virtual void moveAuto() = 0;

    virtual void moveRandom() = 0;

    int getRow() const;

    void setRow(int newRow);

    int getCol() const;

    void setCol(int newCol);

    int getMovimentos() const;

    void resetMovimento();

    std::string getBestMove(Mapa *m, int targetRow, int targetCol) const;

    int getMaxJogadasPTurno() const;

    //RANDOM MODE / AUTO MODE GETTERS E SETTERS

    int getTurnosParaDesaparecer() const;

    bool getAutoPilot() const;

    void setAutoPilot();

    void setRandomMode();

    bool getRandomMode() const;

    void addTurnosEmRandom();

    void setTurnosEmRandom(int turnos);

    //DESTRUIR GETTERS E SETTERS

    bool getEstado() const;

    void setDestruida();

    //EXTRA GETTERS E SETTERS

    virtual void tempestade() = 0;

    virtual std::string showInfo() const;

    char getCidadeName() const;

    void setCidadeName(char newCidadeName);

    Mapa *getMapa() const;

    bool getAutoFase() const;

    void setAutoFase();

private:
    Mapa *onde;
    char caravanaID;
    char cidadeName;

    int row, col;
    int nPessoas, maxPessoas;
    int nivelAgua, maxAgua;
    int nMercadoria, maxMercadoria;
    bool destruida, autoPilot, randomMode;
    bool autoFase;

    const int maxJogadasPTurno;
    int movimentos;
    int turnosParaDesparecer, turnosEmRandom;
};


#endif //SUPPORT_TP_CARAVANA_H
