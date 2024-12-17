#ifndef SUPPORT_TP_CARAVANA_H
#define SUPPORT_TP_CARAVANA_H

#include <string>
#include <ctime>
#include <sstream>
#include <iostream>

class Caravana {
public:
    Caravana(int row, int col, char id, int nPessoas, int maxPessoas, int maxAgua,
             int maxJogadasPTurno,
             double maxMercadoria, bool controlavel);

    ~Caravana();

    //PESSOAS
    int getNPessoas() const;

    int getmaxPessoas() const;

    void adicionaPessoas(int pessoasAAdicionar);

    void removePessoas(int pessoasARemover);

    void setNPessoas(int numeroPessoas);

    //AGUA
    int getnivelAgua() const;

    int getMaxAgua() const;

    //TF - pode não ser preciso
    void removerAgua(int aguaARemover);

    void setNivelAgua(int nivelAgua);

    void abastecerAgua();

    //ID
    char getID() const;

    void setID(char newID);

    //MERCADORIA
    int getMercadoria() const;

    int getMaxMercadoria() const;

    bool adicionaMercadoria(int mercadoriaAAdicionar);

    void removeMercadoria(int mercadoriaARemover);

    void setMercadoria(int novaMercadoria);

    //MOVIMENTOS
    int getMovimentos() const;

    void setMovimentos(int movimentosADefinir);

    void resetMovimento();

    int getMaxJogadasPTurno() const;

    //RANDOM MODE / AUTO MODE
    void setTurnosParaDesaparecer(int turnos);

    int getTurnosParaDesaparecer();

    virtual void move() = 0;

    virtual void semTripulantes() = 0;

    virtual bool verificaContinuidade() = 0;

    void setAutoPilot();

    bool getAutoPilot();

    void setRandomMode();

    bool getRandomMode();

    //DESTRUIR
    bool getEstado() const;

    void setDestruida();

    //EXTRA
    virtual bool tempestade() = 0;

    virtual std::string showInfo() const;

    bool getInCity() const;

    void setInCity(bool inCity);

private:
    char caravanaID;

    int row, col;
    int nPessoas, maxPessoas;
    int nivelAgua, maxAgua;
    double nMercadoria, maxMercadoria;
    bool controlavel, destruida = false, autoPilot = false, randomMode = false;
    bool vidaInfinita;
    bool inCity;

    const int maxJogadasPTurno;
    int movimentos;
    int turnosParaDesparecer = -1, lifeTime;
};


#endif //SUPPORT_TP_CARAVANA_H
