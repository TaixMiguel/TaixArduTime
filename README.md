# TaixArduTime

Una librería para actualizar la fecha-hora en Arduino

> _Nota:_ es necesario que se tenga acceso a Internet para que la librería funcione correctamente

## Uso:
Se puede instanciar la clase de la siguiente forma:

``` C++
TaixArduTime taixTime;
```

y es tan fácil de utilizar como llamar al método `updateTime()`

``` C++
taixTime.updateTime();
```


### Ejemplo completo

``` C++
#include <taixArduTime.hpp>

void printLocalTime() {
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Fallo al obtener la hora-fecha");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

TaixArduTime taixTime;
taixTime.updateTime();
printLocalTime();
```

### Salida del ejemplo

```
Día de la semana, Mes dd YYYY HH:MM:SS
```
