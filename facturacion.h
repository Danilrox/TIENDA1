#ifndef FACTURACION_H
#define FACTURACION_H
// Estas directivas evitan que el archivo se incluya más de una vez.
// Si FACTURACION_H no ha sido definido antes, se define y se incluye el contenido.
// Esto previene errores de redefinición en el compilador.

#define MAX 100 //tamaño maximo de los arreglos 
#define IVA 0.15 //Porcentaje de IVA

extern char *productos[]; // Declaracion externa del arreglo de nombres de productos 
extern float precios[]; // Declaracion externa del arreglo de precios

//FUNCIONES
void mostrarCatalogo();
void seleccionarProducto(int *producto, int *cantidad);
void agregarProducto(int productosComprados[], int cantidades[], int *contador, int producto, int cantidad);

float calcularSubtotalTotal(int productosComprados[], int cantidades[], int contador);
float calcularIVA(float subtotal);
float calcularDescuento(float subtotal);

void imprimirDetalleCompra(int productosComprados[], int cantidades[], int contador);
void imprimirFactura(float subtotal, float iva, float descuento, float total);
void gestionarPago(float total);

#endif // Fin del archivo de cabecera FACTURACION_H
