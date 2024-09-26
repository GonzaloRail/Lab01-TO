#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase Producto
class Producto {
private:
    string nombre;
    float precio;

public:
    Producto(string nombre, float precio) : nombre(nombre), precio(precio) {}

    string getNombre() const { return nombre; }
    float getPrecio() const { return precio; }

    void mostrarProducto() const {
        cout << nombre << " - $" << precio << endl;
    }
};

// Clase BilleteraElectronica
class BilleteraElectronica {
private:
    float saldo;
    vector<Producto> carrito;
    int productosComprados;

public:
    BilleteraElectronica(float saldoInicial = 0.0) : saldo(saldoInicial), productosComprados(0) {}

    void agregarSaldo(float monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Saldo agregado: $" << monto << endl;
        } else {
            cout << "Monto inválido." << endl;
        }
    }

    void comprarProducto(const Producto& producto) {
        if (saldo >= producto.getPrecio()) {
            carrito.push_back(producto);
            saldo -= producto.getPrecio();
            cout << "Producto " << producto.getNombre() << " agregado al carrito." << endl;
        } else {
            cout << "Saldo insuficiente para comprar " << producto.getNombre() << "." << endl;
        }
    }

    void finalizarCompra() {
        if (!carrito.empty()) {
            productosComprados += carrito.size();
            cout << "Compra finalizada. " << carrito.size() << " productos comprados." << endl;
            carrito.clear();
        } else {
            cout << "El carrito está vacío." << endl;
        }
    }

    void consultarSaldo() const {
        cout << "Saldo disponible: $" << saldo << endl;
    }

    void listarCarrito() const {
        if (!carrito.empty()) {
            cout << "Productos en el carrito:" << endl;
            for (const auto& producto : carrito) {
                producto.mostrarProducto();
            }
        } else {
            cout << "El carrito está vacío." << endl;
        }
    }

    void vaciarCarrito() {
        carrito.clear();
        cout << "Carrito vaciado." << endl;
    }
};

// Función principal
int main() {
    BilleteraElectronica billetera(100.0);  // Inicializa la billetera con 100.0 de saldo

    Producto producto1("Laptop", 50.0);
    Producto producto2("Mouse", 15.0);
    Producto producto3("Teclado", 30.0);

    billetera.consultarSaldo();
    
    billetera.comprarProducto(producto1);
    billetera.comprarProducto(producto2);
    billetera.listarCarrito();
    billetera.finalizarCompra();
    
    billetera.consultarSaldo();
    
    billetera.comprarProducto(producto3);
    billetera.listarCarrito();
    billetera.vaciarCarrito();
    
    billetera.consultarSaldo();
    
    return 0;
}
