
class No {
public:
	Contain *item;
    No *prox;

    No() {}

    Contain* getContain() {
        return item;
    }

    void setContain(Contain *item) {
        this -> item = item;
    }

    No* getProx() {
        return prox;
    }

    void setProx(No *prox) {
        this->prox = prox;
    }
};

class Pilha {
private:
    No *fundo, *topo;
    int estado;

public:
    Pilha();

    No* getFundo(){
    	return fundo;
    }

    void setFundo(No *fundo) {
    	this->fundo = fundo;
    }

    No* getTopo(){
        return topo;
    }

    void setTopo(No *topo){
    	this->topo = topo;
    }

    int getEstado(){
    	return estado;
    }

    void setEstado(int estado){
    	this->estado = estado;
    }

    Contain* desempilha(Contain*);
    void empilha(Contain*);
    bool vazia();
};

Pilha::Pilha() {
    fundo = new No();
    topo = fundo;
    estado = TEMP;
}

bool Pilha::vazia() {
	return topo == fundo;
}

void Pilha::empilha(Contain *item) {
    No *aux = new No();
    topo -> setContain(item);
    aux -> setProx(topo);
    topo = aux;
}

Contain* Pilha::desempilha(Contain *item) {
	No *aux = topo;
	topo = topo->getProx();
	item = topo->getContain();
	delete aux;
	return item;
}
