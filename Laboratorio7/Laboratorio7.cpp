#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    double saldo;
    bool activa;
    int intentosFallidos;
    int mesesInactivo;

public:
    // Constructor
    CuentaBancaria(double _saldo) {
        saldo = _saldo;
        activa = true;
        intentosFallidos = 0;
        mesesInactivo = 0;
    }

    // Devuelve el saldo (para poder verificarlo en main al transferir)
    double obtenerSaldo() {
        return saldo;
    }

    // Verifica si la cuenta está activa
    bool estaActiva() {
        return activa;
    }

    // Cambia el estado (habilitar/deshabilitar) y reinicia intentos fallidos si se habilita
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

    // Mostrar saldo
    void mostrarSaldo() {
        cout << "Saldo actual: " << saldo << endl;
    }

    // Depositar
    void depositar(double monto) {
        if (!activa) {
            cout << "La cuenta esta bloqueada, no puede depositar fondos." << endl;
            return;
        }
        if (monto <= 0) {
            cout << "El monto debe ser mayor que cero." << endl;
            return;
        }
        saldo += monto;
        // Como se realizó una operación, se reinicia la inactividad
        mesesInactivo = 0;
        cout << "Deposito exitoso. Saldo actual: " << saldo << endl;
    }

    // Retirar
    void retirar(double monto) {
        if (!activa) {
            cout << "La cuenta esta bloqueada, no puede retirar fondos." << endl;
            return;
        }
        if (monto <= 0) {
            cout << "El monto debe ser mayor que cero." << endl;
            return;
        }
        if (monto > saldo) {
            cout << "Fondos insuficientes." << endl;
            intentosFallidos++;
			cout << "-----LA CUENTA PUEDE SER BLOQUEADA POR MULTIPLES INTENTOS DE RETIRO FALLIDOS. ADVERTENCIA " << intentosFallidos <<"/3.-----" << endl;
            if (intentosFallidos >= 3) {
                activa = false;
                cout << "Cuenta bloqueada por multiples intentos fallidos." << endl;
            }
            return;
        }
        // Retiro exitoso
        saldo -= monto;
        intentosFallidos = 0;
        // Se reinicia la inactividad
        mesesInactivo = 0;

        cout << "Retiro exitoso. Saldo actual: " << saldo << endl;
        if (saldo < 100) {
            cout << "ADVERTENCIA: su saldo es menor a 100." << endl;
        }
    }

    // Simular el paso de un mes
    void pasarMes() {
        // Si la cuenta ya está bloqueada, no hace nada con la inactividad
        if (!activa) return;

        mesesInactivo++;
        // Si pasan 6 meses sin uso, se bloquea automáticamente
        if (mesesInactivo >= 6) {
            activa = false;
            cout << "La cuenta se ha bloqueado automaticamente por inactividad." << endl;
        }
    }
};

int main() {
    // Creamos 30 cuentas, cada una con saldo inicial de 1000
    CuentaBancaria cuenta1(1000), cuenta2(1000), cuenta3(1000), cuenta4(1000), cuenta5(1000);
    CuentaBancaria cuenta6(1000), cuenta7(1000), cuenta8(1000), cuenta9(1000), cuenta10(1000);
    CuentaBancaria cuenta11(1000), cuenta12(1000), cuenta13(1000), cuenta14(1000), cuenta15(1000);
    CuentaBancaria cuenta16(1000), cuenta17(1000), cuenta18(1000), cuenta19(1000), cuenta20(1000);
    CuentaBancaria cuenta21(1000), cuenta22(1000), cuenta23(1000), cuenta24(1000), cuenta25(1000);
    CuentaBancaria cuenta26(1000), cuenta27(1000), cuenta28(1000), cuenta29(1000), cuenta30(1000);

    int opcion;
    int cuentaOrigen, cuentaDestino;
    double monto;

    do {
        cout << "\n--------- MENU ---------\n";
        cout << "1. Depositar\n";
        cout << "2. Retirar\n";
        cout << "3. Consultar saldo\n";
        cout << "4. Habilitar cuenta\n";
        cout << "5. Deshabilitar cuenta\n";
        cout << "6. Transferir entre cuentas\n";
        cout << "7. Simular paso de 1 mes\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout << "Seleccione la cuenta (1-30) para DEPOSITAR: ";
            cin >> cuentaOrigen;
            if (cuentaOrigen < 1 || cuentaOrigen > 30) {
                cout << "Cuenta no valida." << endl;
                break;
            }
            cout << "Ingrese monto a depositar: ";
            cin >> monto;
            switch (cuentaOrigen) {
            case 1: cuenta1.depositar(monto); break;
            case 2: cuenta2.depositar(monto); break;
            case 3: cuenta3.depositar(monto); break;
            case 4: cuenta4.depositar(monto); break;
            case 5: cuenta5.depositar(monto); break;
            case 6: cuenta6.depositar(monto); break;
            case 7: cuenta7.depositar(monto); break;
            case 8: cuenta8.depositar(monto); break;
            case 9: cuenta9.depositar(monto); break;
            case 10: cuenta10.depositar(monto); break;
            case 11: cuenta11.depositar(monto); break;
            case 12: cuenta12.depositar(monto); break;
            case 13: cuenta13.depositar(monto); break;
            case 14: cuenta14.depositar(monto); break;
            case 15: cuenta15.depositar(monto); break;
            case 16: cuenta16.depositar(monto); break;
            case 17: cuenta17.depositar(monto); break;
            case 18: cuenta18.depositar(monto); break;
            case 19: cuenta19.depositar(monto); break;
            case 20: cuenta20.depositar(monto); break;
            case 21: cuenta21.depositar(monto); break;
            case 22: cuenta22.depositar(monto); break;
            case 23: cuenta23.depositar(monto); break;
            case 24: cuenta24.depositar(monto); break;
            case 25: cuenta25.depositar(monto); break;
            case 26: cuenta26.depositar(monto); break;
            case 27: cuenta27.depositar(monto); break;
            case 28: cuenta28.depositar(monto); break;
            case 29: cuenta29.depositar(monto); break;
            case 30: cuenta30.depositar(monto); break;
            }
            break;
        }
        case 2: {
            cout << "Seleccione la cuenta (1-30) para RETIRAR: ";
            cin >> cuentaOrigen;
            if (cuentaOrigen < 1 || cuentaOrigen > 30) {
                cout << "Cuenta no valida." << endl;
                break;
            }
            cout << "Ingrese monto a retirar: ";
            cin >> monto;
            switch (cuentaOrigen) {
            case 1: cuenta1.retirar(monto); break;
            case 2: cuenta2.retirar(monto); break;
            case 3: cuenta3.retirar(monto); break;
            case 4: cuenta4.retirar(monto); break;
            case 5: cuenta5.retirar(monto); break;
            case 6: cuenta6.retirar(monto); break;
            case 7: cuenta7.retirar(monto); break;
            case 8: cuenta8.retirar(monto); break;
            case 9: cuenta9.retirar(monto); break;
            case 10: cuenta10.retirar(monto); break;
            case 11: cuenta11.retirar(monto); break;
            case 12: cuenta12.retirar(monto); break;
            case 13: cuenta13.retirar(monto); break;
            case 14: cuenta14.retirar(monto); break;
            case 15: cuenta15.retirar(monto); break;
            case 16: cuenta16.retirar(monto); break;
            case 17: cuenta17.retirar(monto); break;
            case 18: cuenta18.retirar(monto); break;
            case 19: cuenta19.retirar(monto); break;
            case 20: cuenta20.retirar(monto); break;
            case 21: cuenta21.retirar(monto); break;
            case 22: cuenta22.retirar(monto); break;
            case 23: cuenta23.retirar(monto); break;
            case 24: cuenta24.retirar(monto); break;
            case 25: cuenta25.retirar(monto); break;
            case 26: cuenta26.retirar(monto); break;
            case 27: cuenta27.retirar(monto); break;
            case 28: cuenta28.retirar(monto); break;
            case 29: cuenta29.retirar(monto); break;
            case 30: cuenta30.retirar(monto); break;
            }
            break;
        }
        case 3: {
            cout << "Seleccione la cuenta (1-30) para CONSULTAR SALDO: ";
            cin >> cuentaOrigen;
            if (cuentaOrigen < 1 || cuentaOrigen > 30) {
                cout << "Cuenta no valida." << endl;
                break;
            }
            switch (cuentaOrigen) {
            case 1: cuenta1.mostrarSaldo(); break;
            case 2: cuenta2.mostrarSaldo(); break;
            case 3: cuenta3.mostrarSaldo(); break;
            case 4: cuenta4.mostrarSaldo(); break;
            case 5: cuenta5.mostrarSaldo(); break;
            case 6: cuenta6.mostrarSaldo(); break;
            case 7: cuenta7.mostrarSaldo(); break;
            case 8: cuenta8.mostrarSaldo(); break;
            case 9: cuenta9.mostrarSaldo(); break;
            case 10: cuenta10.mostrarSaldo(); break;
            case 11: cuenta11.mostrarSaldo(); break;
            case 12: cuenta12.mostrarSaldo(); break;
            case 13: cuenta13.mostrarSaldo(); break;
            case 14: cuenta14.mostrarSaldo(); break;
            case 15: cuenta15.mostrarSaldo(); break;
            case 16: cuenta16.mostrarSaldo(); break;
            case 17: cuenta17.mostrarSaldo(); break;
            case 18: cuenta18.mostrarSaldo(); break;
            case 19: cuenta19.mostrarSaldo(); break;
            case 20: cuenta20.mostrarSaldo(); break;
            case 21: cuenta21.mostrarSaldo(); break;
            case 22: cuenta22.mostrarSaldo(); break;
            case 23: cuenta23.mostrarSaldo(); break;
            case 24: cuenta24.mostrarSaldo(); break;
            case 25: cuenta25.mostrarSaldo(); break;
            case 26: cuenta26.mostrarSaldo(); break;
            case 27: cuenta27.mostrarSaldo(); break;
            case 28: cuenta28.mostrarSaldo(); break;
            case 29: cuenta29.mostrarSaldo(); break;
            case 30: cuenta30.mostrarSaldo(); break;
            }
            break;
        }
        case 4: {
            cout << "Seleccione la cuenta (1-30) para HABILITAR: ";
            cin >> cuentaOrigen;
            if (cuentaOrigen < 1 || cuentaOrigen > 30) {
                cout << "Cuenta no valida." << endl;
                break;
            }
            switch (cuentaOrigen) {
            case 1: cuenta1.cambiarEstado(true); break;
            case 2: cuenta2.cambiarEstado(true); break;
            case 3: cuenta3.cambiarEstado(true); break;
            case 4: cuenta4.cambiarEstado(true); break;
            case 5: cuenta5.cambiarEstado(true); break;
            case 6: cuenta6.cambiarEstado(true); break;
            case 7: cuenta7.cambiarEstado(true); break;
            case 8: cuenta8.cambiarEstado(true); break;
            case 9: cuenta9.cambiarEstado(true); break;
            case 10: cuenta10.cambiarEstado(true); break;
            case 11: cuenta11.cambiarEstado(true); break;
            case 12: cuenta12.cambiarEstado(true); break;
            case 13: cuenta13.cambiarEstado(true); break;
            case 14: cuenta14.cambiarEstado(true); break;
            case 15: cuenta15.cambiarEstado(true); break;
            case 16: cuenta16.cambiarEstado(true); break;
            case 17: cuenta17.cambiarEstado(true); break;
            case 18: cuenta18.cambiarEstado(true); break;
            case 19: cuenta19.cambiarEstado(true); break;
            case 20: cuenta20.cambiarEstado(true); break;
            case 21: cuenta21.cambiarEstado(true); break;
            case 22: cuenta22.cambiarEstado(true); break;
            case 23: cuenta23.cambiarEstado(true); break;
            case 24: cuenta24.cambiarEstado(true); break;
            case 25: cuenta25.cambiarEstado(true); break;
            case 26: cuenta26.cambiarEstado(true); break;
            case 27: cuenta27.cambiarEstado(true); break;
            case 28: cuenta28.cambiarEstado(true); break;
            case 29: cuenta29.cambiarEstado(true); break;
            case 30: cuenta30.cambiarEstado(true); break;
            }
            break;
        }
        case 5: {
            cout << "Seleccione la cuenta (1-30) para DESHABILITAR: ";
            cin >> cuentaOrigen;
            if (cuentaOrigen < 1 || cuentaOrigen > 30) {
                cout << "Cuenta no valida." << endl;
                break;
            }
            switch (cuentaOrigen) {
            case 1: cuenta1.cambiarEstado(false); break;
            case 2: cuenta2.cambiarEstado(false); break;
            case 3: cuenta3.cambiarEstado(false); break;
            case 4: cuenta4.cambiarEstado(false); break;
            case 5: cuenta5.cambiarEstado(false); break;
            case 6: cuenta6.cambiarEstado(false); break;
            case 7: cuenta7.cambiarEstado(false); break;
            case 8: cuenta8.cambiarEstado(false); break;
            case 9: cuenta9.cambiarEstado(false); break;
            case 10: cuenta10.cambiarEstado(false); break;
            case 11: cuenta11.cambiarEstado(false); break;
            case 12: cuenta12.cambiarEstado(false); break;
            case 13: cuenta13.cambiarEstado(false); break;
            case 14: cuenta14.cambiarEstado(false); break;
            case 15: cuenta15.cambiarEstado(false); break;
            case 16: cuenta16.cambiarEstado(false); break;
            case 17: cuenta17.cambiarEstado(false); break;
            case 18: cuenta18.cambiarEstado(false); break;
            case 19: cuenta19.cambiarEstado(false); break;
            case 20: cuenta20.cambiarEstado(false); break;
            case 21: cuenta21.cambiarEstado(false); break;
            case 22: cuenta22.cambiarEstado(false); break;
            case 23: cuenta23.cambiarEstado(false); break;
            case 24: cuenta24.cambiarEstado(false); break;
            case 25: cuenta25.cambiarEstado(false); break;
            case 26: cuenta26.cambiarEstado(false); break;
            case 27: cuenta27.cambiarEstado(false); break;
            case 28: cuenta28.cambiarEstado(false); break;
            case 29: cuenta29.cambiarEstado(false); break;
            case 30: cuenta30.cambiarEstado(false); break;
            }
            break;
        }
        case 6: {
            // Transferir
            cout << "Seleccione la cuenta ORIGEN (1-30): ";
            cin >> cuentaOrigen;
            cout << "Seleccione la cuenta DESTINO (1-30): ";
            cin >> cuentaDestino;
            if (cuentaOrigen < 1 || cuentaOrigen > 30 ||
                cuentaDestino < 1 || cuentaDestino > 30 ||
                cuentaOrigen == cuentaDestino) {
                cout << "Cuentas no validas." << endl;
                break;
            }
            cout << "Ingrese monto a transferir: ";
            cin >> monto;

            // Para "simular" una transferencia manualmente:
            // 1) Se intenta retirar de la cuenta origen
            // 2) Si el retiro fue exitoso (comparamos saldo antes y despues),
            //    se deposita en la cuenta destino.

            double saldoAntes = 0.0;
            double saldoDespues = 0.0;
            bool retiroExitoso = false;

            // Retiramos de la cuenta origen
            switch (cuentaOrigen) {
            case 1:
                saldoAntes = cuenta1.obtenerSaldo();
                cuenta1.retirar(monto);
                saldoDespues = cuenta1.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 2:
                saldoAntes = cuenta2.obtenerSaldo();
                cuenta2.retirar(monto);
                saldoDespues = cuenta2.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 3:
                saldoAntes = cuenta3.obtenerSaldo();
                cuenta3.retirar(monto);
                saldoDespues = cuenta3.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 4:
                saldoAntes = cuenta4.obtenerSaldo();
                cuenta4.retirar(monto);
                saldoDespues = cuenta4.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 5:
                saldoAntes = cuenta5.obtenerSaldo();
                cuenta5.retirar(monto);
                saldoDespues = cuenta5.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 6:
                saldoAntes = cuenta6.obtenerSaldo();
                cuenta6.retirar(monto);
                saldoDespues = cuenta6.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 7:
                saldoAntes = cuenta7.obtenerSaldo();
                cuenta7.retirar(monto);
                saldoDespues = cuenta7.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 8:
                saldoAntes = cuenta8.obtenerSaldo();
                cuenta8.retirar(monto);
                saldoDespues = cuenta8.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 9:
                saldoAntes = cuenta9.obtenerSaldo();
                cuenta9.retirar(monto);
                saldoDespues = cuenta9.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 10:
                saldoAntes = cuenta10.obtenerSaldo();
                cuenta10.retirar(monto);
                saldoDespues = cuenta10.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 11:
                saldoAntes = cuenta11.obtenerSaldo();
                cuenta11.retirar(monto);
                saldoDespues = cuenta11.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 12:
                saldoAntes = cuenta12.obtenerSaldo();
                cuenta12.retirar(monto);
                saldoDespues = cuenta12.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 13:
                saldoAntes = cuenta13.obtenerSaldo();
                cuenta13.retirar(monto);
                saldoDespues = cuenta13.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 14:
                saldoAntes = cuenta14.obtenerSaldo();
                cuenta14.retirar(monto);
                saldoDespues = cuenta14.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 15:
                saldoAntes = cuenta15.obtenerSaldo();
                cuenta15.retirar(monto);
                saldoDespues = cuenta15.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 16:
                saldoAntes = cuenta16.obtenerSaldo();
                cuenta16.retirar(monto);
                saldoDespues = cuenta16.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 17:
                saldoAntes = cuenta17.obtenerSaldo();
                cuenta17.retirar(monto);
                saldoDespues = cuenta17.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 18:
                saldoAntes = cuenta18.obtenerSaldo();
                cuenta18.retirar(monto);
                saldoDespues = cuenta18.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 19:
                saldoAntes = cuenta19.obtenerSaldo();
                cuenta19.retirar(monto);
                saldoDespues = cuenta19.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 20:
                saldoAntes = cuenta20.obtenerSaldo();
                cuenta20.retirar(monto);
                saldoDespues = cuenta20.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 21:
                saldoAntes = cuenta21.obtenerSaldo();
                cuenta21.retirar(monto);
                saldoDespues = cuenta21.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 22:
                saldoAntes = cuenta22.obtenerSaldo();
                cuenta22.retirar(monto);
                saldoDespues = cuenta22.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 23:
                saldoAntes = cuenta23.obtenerSaldo();
                cuenta23.retirar(monto);
                saldoDespues = cuenta23.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 24:
                saldoAntes = cuenta24.obtenerSaldo();
                cuenta24.retirar(monto);
                saldoDespues = cuenta24.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 25:
                saldoAntes = cuenta25.obtenerSaldo();
                cuenta25.retirar(monto);
                saldoDespues = cuenta25.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 26:
                saldoAntes = cuenta26.obtenerSaldo();
                cuenta26.retirar(monto);
                saldoDespues = cuenta26.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 27:
                saldoAntes = cuenta27.obtenerSaldo();
                cuenta27.retirar(monto);
                saldoDespues = cuenta27.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 28:
                saldoAntes = cuenta28.obtenerSaldo();
                cuenta28.retirar(monto);
                saldoDespues = cuenta28.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 29:
                saldoAntes = cuenta29.obtenerSaldo();
                cuenta29.retirar(monto);
                saldoDespues = cuenta29.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            case 30:
                saldoAntes = cuenta30.obtenerSaldo();
                cuenta30.retirar(monto);
                saldoDespues = cuenta30.obtenerSaldo();
                if (saldoDespues < saldoAntes) retiroExitoso = true;
                break;
            }

            // Si el retiro fue exitoso, depositamos en la cuenta destino
            if (retiroExitoso) {
                switch (cuentaDestino) {
                case 1: cuenta1.depositar(monto); break;
                case 2: cuenta2.depositar(monto); break;
                case 3: cuenta3.depositar(monto); break;
                case 4: cuenta4.depositar(monto); break;
                case 5: cuenta5.depositar(monto); break;
                case 6: cuenta6.depositar(monto); break;
                case 7: cuenta7.depositar(monto); break;
                case 8: cuenta8.depositar(monto); break;
                case 9: cuenta9.depositar(monto); break;
                case 10: cuenta10.depositar(monto); break;
                case 11: cuenta11.depositar(monto); break;
                case 12: cuenta12.depositar(monto); break;
                case 13: cuenta13.depositar(monto); break;
                case 14: cuenta14.depositar(monto); break;
                case 15: cuenta15.depositar(monto); break;
                case 16: cuenta16.depositar(monto); break;
                case 17: cuenta17.depositar(monto); break;
                case 18: cuenta18.depositar(monto); break;
                case 19: cuenta19.depositar(monto); break;
                case 20: cuenta20.depositar(monto); break;
                case 21: cuenta21.depositar(monto); break;
                case 22: cuenta22.depositar(monto); break;
                case 23: cuenta23.depositar(monto); break;
                case 24: cuenta24.depositar(monto); break;
                case 25: cuenta25.depositar(monto); break;
                case 26: cuenta26.depositar(monto); break;
                case 27: cuenta27.depositar(monto); break;
                case 28: cuenta28.depositar(monto); break;
                case 29: cuenta29.depositar(monto); break;
                case 30: cuenta30.depositar(monto); break;
                }
                cout << "Transferencia realizada con exito." << endl;
            }
            break;
        }
        case 7: {
            // Simular el paso de un mes en TODAS las cuentas
            cuenta1.pasarMes();   cuenta2.pasarMes();   cuenta3.pasarMes();
            cuenta4.pasarMes();   cuenta5.pasarMes();   cuenta6.pasarMes();
            cuenta7.pasarMes();   cuenta8.pasarMes();   cuenta9.pasarMes();
            cuenta10.pasarMes();  cuenta11.pasarMes();  cuenta12.pasarMes();
            cuenta13.pasarMes();  cuenta14.pasarMes();  cuenta15.pasarMes();
            cuenta16.pasarMes();  cuenta17.pasarMes();  cuenta18.pasarMes();
            cuenta19.pasarMes();  cuenta20.pasarMes();  cuenta21.pasarMes();
            cuenta22.pasarMes();  cuenta23.pasarMes();  cuenta24.pasarMes();
            cuenta25.pasarMes();  cuenta26.pasarMes();  cuenta27.pasarMes();
            cuenta28.pasarMes();  cuenta29.pasarMes();  cuenta30.pasarMes();

            cout << "Se ha simulado el paso de 1 mes en todas las cuentas." << endl;
            break;
        }
        case 8:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    } while (opcion != 8);

    return 0;
}
