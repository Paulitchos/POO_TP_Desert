#ifndef SUPPORT_TP_CARAVANA_H
#define SUPPORT_TP_CARAVANA_H

#include <string>
#include <ctime>
#include <sstream>
#include <iostream>

class Caravana {
public:
    Caravana(int nPessoas, int maxPessoas, int maxAgua,
             int maxJogadasPTurno,
             double maxMercadoria, bool controlavel);

    ~Caravana();

    //PESSOAS
    int getnPessoas() const;

    int getmaxPessoas() const;

    void adicionaPessoas(int pessoasAAdicionar);

    void removePessoas(int pessoasARemover);

    void setPessoas(int numeroPessoas);

    //AGUA
    int getnivelAgua() const;

    int getMaxAgua() const;

    //TF - pode não ser preciso
    void removerAgua(int aguaARemover);

    void setNivelAgua(int nivelAgua);

    void abastecerAgua();

    //ID
    int getID() const;

    void setID(int newID);

    //MERCADORIA
    int getMercadoria() const;

    int getMaxMercadoria() const;

    void adicionaMercadoria(int mercadoriaAAdicionar);

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

    int getPreco() const;

    virtual std::string showInfo() const;

private:
    int caravanaID;
    static int preco;

    int nPessoas, maxPessoas;
    int nivelAgua, maxAgua;
    double nMercadoria, maxMercadoria;
    bool controlavel, destruida = false, autoPilot = false, randomMode = false;
    bool vidaInfinita;

    const int maxJogadasPTurno;
    int movimentos;
    int turnosParaDesparecer = -1, lifeTime;
};


#endif //SUPPORT_TP_CARAVANA_H
