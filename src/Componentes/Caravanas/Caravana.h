#ifndef SUPPORT_TP_CARAVANA_H
#define SUPPORT_TP_CARAVANA_H

#include <string>
#include <sstream>
#include <iostream>

class Mapa;

class Caravana {
public:
    Caravana(int row, int col, char id, int nPessoas, int maxPessoas, int maxAgua,
             int maxJogadasPTurno,
             double maxMercadoria, bool controlavel, Mapa *onde);

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
    bool move(const std::string &direction);

    virtual void moveAuto() = 0;

    int getRow() const;

    void setRow(int newRow);

    int getCol() const;

    void setCol(int newCol);

    int getMovimentos() const;

    void setMovimentos();

    void resetMovimento();

    std::string getBestMove(Mapa *m, int targetRow, int targetCol);

    int getMaxJogadasPTurno() const;

    //RANDOM MODE / AUTO MODE
    void setTurnosParaDesaparecer(int turnos);

    int getTurnosParaDesaparecer();

    virtual void semTripulantes() = 0;

    virtual bool verificaContinuidade() = 0;

    bool getAutoPilot();

    void setAutoPilot();

    void setRandomMode();

    bool getRandomMode();

    //DESTRUIR
    bool getEstado() const;

    void setDestruida();

    //EXTRA
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
    double nMercadoria, maxMercadoria;
    bool controlavel, destruida, autoPilot, randomMode;
    bool vidaInfinita;
    bool autoFase;

    const int maxJogadasPTurno;
    int movimentos;
    int turnosParaDesparecer, lifeTime;
};


#endif //SUPPORT_TP_CARAVANA_H
