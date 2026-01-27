#ifndef FACTURACION_H
#define FACTURACION_H

#define MAX 100
#define IVA 0.15

extern char *productos[];
extern float precios[];

void mostrarCatalogo();
void seleccionarProducto(int *producto, int *cantidad);
void agregarProducto(int productosComprados[], int cantidades[], int *contador, int producto, int cantidad);

float calcularSubtotalTotal(int productosComprados[], int cantidades[], int contador);
float calcularIVA(float subtotal);
float calcularDescuento(float subtotal);

void imprimirDetalleCompra(int productosComprados[], int cantidades[], int contador);
void imprimirFactura(float subtotal, float iva, float descuento, float total);
void gestionarPago(float total);

#endif
