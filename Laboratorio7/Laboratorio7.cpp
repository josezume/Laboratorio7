#include <iostream>

using namespace std;

class CuentaBancaria {
private:
    double saldo;
    bool activa;
    int intentosFallidos;

public:
    CuentaBancaria(double _saldo) {
        saldo = _saldo;
        activa = true;
        intentosFallidos = 0;
    }

    void depositar(double monto) {
        if (monto <= 0) {
            cout << "El monto debe ser mayor que cero." << endl;
            return;
        }
        saldo += monto;
        cout << "Deposito exitoso, saldo actual: " << saldo << endl;
    }

    void retirar(double monto) {
        if (!activa) {
            cout << "La cuenta esta deshabilitada, no puede retirar fondos." << endl;
            return;
        }
        if (monto <= 0) {
            cout << "El monto debe ser mayor que cero." << endl;
            return;
        }
        if (monto > saldo) {
            cout << "Fondos insuficientes" << endl;
            intentosFallidos++;
            if (intentosFallidos >= 3) {
                activa = false;
                cout << "Cuenta deshabilitada por multiples intentos fallidos." << endl;
            }
            return;
        }
        saldo -= monto;
        intentosFallidos = 0;
        cout << "Retiro exitoso, saldo actual: " << saldo << endl;
    }

    void transferir(CuentaBancaria destino, double monto) {
        if (!activa) {
            cout << "La cuenta esta deshabilitada, no puede realizar transferencias." << endl;
            return;
        }
        if (!destino.estaActiva()) {
            cout << "La cuenta destino esta deshabilitada, no se puede transferir." << endl;
            return;
        }
        if (monto <= 0) {
            cout << "El monto debe ser mayor que cero." << endl;
            return;
        }
        if (monto > saldo) {
            cout << "Fondos insuficientes para la transferencia." << endl;
            return;
        }
        saldo -= monto;
        destino.depositar(monto);
        cout << "Transferencia exitosa." << endl;
    }

    void mostrarSaldo() {
        cout << "Su saldo es: " << saldo << endl;
    }

    void cambiarEstado(bool estado) {
        activa = estado;
        if (activa) {
            intentosFallidos = 0;
            cout << "Cuenta habilitada." << endl;
        }
        else {
            cout << "Cuenta deshabilitada." << endl;
        }
    }

    bool estaActiva() {
        return activa;
    }
};

int main() {
    int opcion, cuentaOrigen, cuentaDestino;
    double monto;

    CuentaBancaria cuenta1(1000), cuenta2(1000), cuenta3(1000), cuenta4(1000), cuenta5(1000);
    CuentaBancaria cuenta6(1000), cuenta7(1000), cuenta8(1000), cuenta9(1000), cuenta10(1000);
    CuentaBancaria cuenta11(1000), cuenta12(1000), cuenta13(1000), cuenta14(1000), cuenta15(1000);
    CuentaBancaria cuenta16(1000), cuenta17(1000), cuenta18(1000), cuenta19(1000), cuenta20(1000);
    CuentaBancaria cuenta21(1000), cuenta22(1000), cuenta23(1000), cuenta24(1000), cuenta25(1000);
    CuentaBancaria cuenta26(1000), cuenta27(1000), cuenta28(1000), cuenta29(1000), cuenta30(1000);

    do {
        cout << "Seleccione una opcion:\n1. Depositar\n2. Retirar\n3. Consultar saldo\n4. Habilitar cuenta\n5. Deshabilitar cuenta\n6. Transferir entre cuentas\n7. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << "Seleccione la cuenta (1-30): ";
            cin >> cuentaOrigen;
            if (cuentaOrigen < 1 || cuentaOrigen > 30) {
                cout << "Cuenta no valida." << endl;
                break;
            }
            if (opcion == 1) { cout << "Ingrese monto a depositar: "; cin >> monto; }
            if (opcion == 2) { cout << "Ingrese monto a retirar: "; cin >> monto; }
            if (opcion == 4) { cout << "Cuenta habilitada." << endl; }
            if (opcion == 5) { cout << "Cuenta deshabilitada." << endl; }
            break;
        case 6:
            cout << "Seleccione la cuenta origen (1-30): ";
            cin >> cuentaOrigen;
            cout << "Seleccione la cuenta destino (1-30): ";
            cin >> cuentaDestino;
            if (cuentaOrigen < 1 || cuentaOrigen > 30 || cuentaDestino < 1 || cuentaDestino > 30 || cuentaOrigen == cuentaDestino) {
                cout << "Cuentas no validas." << endl;
                break;
            }
            cout << "Ingrese monto a transferir: ";
            cin >> monto;
            cout << "Transferencia realizada." << endl;
            break;
        case 7:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    } while (opcion != 7);
    return 0;
}
