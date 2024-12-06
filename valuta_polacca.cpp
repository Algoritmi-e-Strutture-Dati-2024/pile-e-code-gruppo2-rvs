#include <iostream>

double valuta_polacca(Coda<string>& post) {
    Pila<double> valuta;

    while (!post.isEmpty()) {
        string t = post.frontElem();
        post.dequeue();

        if (isdigit(t[0]) || (t.size() > 1 && isdigit(t[1]))) {
            valuta.push(stod(t));
        } else {
            if (valuta.size() < 2) {
                cerr << "ERROR ---> Espressione non valutaida." << endl;
                return 0;
            }
            double numTop = valuta.pop();
            double numSuccessivo = valuta.pop();

            double ris = 0;
            if (t == "+") {
                ris = numSuccessivo + numTop;
            } else if (t == "-") {
                ris = numSuccessivo - numTop;
            } else if (t == "*") {
                ris = numSuccessivo * numTop;
            } else if (t == "/") {
                if (numTop == 0) {
                    cerr << "ERROR ---> Divisione per zero." << endl;
                    return 0;
                }
        

