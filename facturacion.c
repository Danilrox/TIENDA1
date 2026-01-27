#include <stdio.h>
#include "facturacion.h"

// Listas 
char *productos[] = {
    "Blusa", "Pantalon", "Medias", "Chompa", "Chaqueta", "Short",
    "Zapatos", "Camisas", "Camisetas", "Pantalonetas", "Calentadores", "Faldas"
};

float precios[] = {
    10.00, 20.00, 2.50, 15.00, 18.00, 7.00,
    35.00, 15.00, 8.00, 9.00, 15.00, 8.00
};

//Muestra el catalogo de ropa 
void mostrarCatalogo() {
    printf("\n===== CATALOGO DE ROPA =====\n");
    for (int i = 0; i < 12; i++) {
        printf("%d. %-15s $%.2f\n", i + 1, productos[i], precios[i]);
    }
}

//Funcion para seleccionar el producto
void seleccionarProducto(int *producto, int *cantidad) {
    do {
        printf("\nSeleccione el producto (1-12): ");
        scanf("%d", producto);
    } while (*producto < 1 || *producto > 12);

    printf("Ingrese la cantidad: ");
    scanf("%d", cantidad);
}

void agregarProducto(int productosComprados[], int cantidades[], int *contador, int producto, int cantidad) {
    // se cambia el valor de la variable contador desde esta funcion.
    productosComprados[*contador] = producto - 1; //Guarda el indice del producto en la posicion contador.
    cantidades[*contador] = cantidad; // Guarda la cantidad correspondiente en la posicion contador.
    (*contador)++; //Contador va a umentando una unidad cada q se llame a la funcion.
}

//Funcion para calcular el subtotal de todas las compras
float calcularSubtotalTotal(int productosComprados[], int cantidades[], int contador) {
    float subtotal = 0;
    //Se repite el bucle mientras hayan productos 
    for (int i = 0; i < contador; i++) {
        subtotal += precios[productosComprados[i]] * cantidades[i];
    }
    return subtotal;
}

//Funcion para calcular el IVA de todas las compras 
float calcularIVA(float subtotal) {
    return subtotal * IVA;
}

float calcularDescuento(float subtotal) {
    if (subtotal >= 100)
        return subtotal * 0.10;
    return 0;
}

void imprimirDetalleCompra(int productosComprados[], int cantidades[], int contador) {
    printf("\n===== DETALLE DE COMPRA =====\n");
    printf("%-15s %-10s %-10s %-10s\n", "Producto", "Precio", "Cantidad", "Subtotal");

    for (int i = 0; i < contador; i++) {
        int idx = productosComprados[i]; // indice que indica la posición de un producto en los arreglos
        float sub = precios[idx] * cantidades[i]; //Precio subtotal del producto

        printf("%-15s $%-9.2f %-10d $%-9.2f\n",
               productos[idx], precios[idx], cantidades[i], sub); //Subtotal de cada producto
    }
}

//Funcion para imprimir la factura 
void imprimirFactura(float subtotal, float iva, float descuento, float total) {
    printf("\n===== FACTURA FINAL =====\n");
    printf("Subtotal:   $%.2f\n", subtotal);
    printf("IVA (15%%):  $%.2f\n", iva);
    printf("Descuento:  $%.2f\n", descuento);
    printf("TOTAL:      $%.2f\n", total);
}

//Gestion de pago final 
void gestionarPago(float total) {
    float pago;
    printf("\nIngrese el valor de pago: ");
    scanf("%f", &pago);

    //Controlo de pago 
    if (pago > total)
        printf("Vuelto: $%.2f\n", pago - total);
    else if (pago == total)
        printf("Pago exacto.\n");
    else
        printf("Faltan: $%.2f\n", total - pago);
}
