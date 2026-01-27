#include <stdio.h>
#include "facturacion.h"
//hola 
// Listas 
char *productos[] = {
    "Blusa", "Pantalon", "Medias", "Chompa", "Chaqueta", "Short",
    "Zapatos", "Camisas", "Camisetas", "Pantalonetas", "Calentadores", "Faldas"
};

float precios[] = {
    10.00, 20.00, 2.50, 15.00, 18.00, 7.00,
    35.00, 15.00, 8.00, 9.00, 15.00, 8.00
};

void mostrarCatalogo() {
    printf("\n===== CATALOGO DE ROPA =====\n");
    for (int i = 0; i < 12; i++) {
        printf("%d. %-15s $%.2f\n", i + 1, productos[i], precios[i]);
    }
}

void seleccionarProducto(int *producto, int *cantidad) {
    do {
        printf("\nSeleccione el producto (1-12): ");
        scanf("%d", producto);
    } while (*producto < 1 || *producto > 12);

    printf("Ingrese la cantidad: ");
    scanf("%d", cantidad);
}

void agregarProducto(int productosComprados[], int cantidades[], int *contador, int producto, int cantidad) {
    productosComprados[*contador] = producto - 1;
    cantidades[*contador] = cantidad;
    (*contador)++;
}

float calcularSubtotalTotal(int productosComprados[], int cantidades[], int contador) {
    float subtotal = 0;
    for (int i = 0; i < contador; i++) {
        subtotal += precios[productosComprados[i]] * cantidades[i];
    }
    return subtotal;
}

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
        int idx = productosComprados[i];
        float sub = precios[idx] * cantidades[i];

        printf("%-15s $%-9.2f %-10d $%-9.2f\n",
               productos[idx], precios[idx], cantidades[i], sub);
    }
}

void imprimirFactura(float subtotal, float iva, float descuento, float total) {
    printf("\n===== FACTURA FINAL =====\n");
    printf("Subtotal:   $%.2f\n", subtotal);
    printf("IVA (15%%):  $%.2f\n", iva);
    printf("Descuento:  $%.2f\n", descuento);
    printf("TOTAL:      $%.2f\n", total);
}

void gestionarPago(float total) {
    float pago;
    printf("\nIngrese el valor de pago: ");
    scanf("%f", &pago);

    if (pago > total)
        printf("Vuelto: $%.2f\n", pago - total);
    else if (pago == total)
        printf("Pago exacto.\n");
    else
        printf("Faltan: $%.2f\n", total - pago);
}
