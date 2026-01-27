#include <stdio.h>
#include "facturacion.h"

int main() {
    int producto, cantidad;
    int productosComprados[MAX]; //Lista con los ndices de los productos comprados por el usuario
    int cantidades[MAX]; //Lista con la cantidad de cada producto 
    int contador = 0; //Numero de prodtuctos que elige el clinete y se inicializa el contador en 0
    char opcion; //Variable para verificar si el cliente quiere seguir comprando 

    while (1) {

        // Ciclo de agregar productos 
        do {
            mostrarCatalogo();
            seleccionarProducto(&producto, &cantidad);
            agregarProducto(productosComprados, cantidades, &contador, producto, cantidad);

            printf("\nDesea agregar otro producto? (s/n): ");
            scanf(" %c", &opcion);

        } while ((opcion == 's' || opcion == 'S') && contador < MAX);

        // Calculos 
        float subtotal = calcularSubtotalTotal(productosComprados, cantidades, contador);
        float iva = calcularIVA(subtotal);
        float descuento = calcularDescuento(subtotal);
        float total = subtotal + iva - descuento;

        // Mostrar factura
        imprimirDetalleCompra(productosComprados, cantidades, contador);
        imprimirFactura(subtotal, iva, descuento, total);

        // Decisión del usuario 
        printf("\nDesea continuar, terminar o reiniciar la factura?\n");
        printf("s = continuar | n = pagar | r = reiniciar\n");
        scanf(" %c", &opcion);

        if (opcion == 'n' || opcion == 'N') {
            gestionarPago(total); // Gestion del pago final
            break;
        }

        if (opcion == 'r' || opcion == 'R') {
            contador = 0;
            printf("\nFactura reiniciada.\n");
        }
        // Si es 's', el ciclo continúa y se agregan más productos 
    }

    printf("\nSistema finalizado. Gracias por su compra.\n");
    return 0;
}
