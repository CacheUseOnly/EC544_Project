# Controller

*need a better title for this readme*

Running examples
```
>>> CW-3
select motor 3
Rotate clockwise
>>> CC-6
select motor 6
Rotate counter-clockwise
```
## Server Set Up

1. In order to use the GPIO ports your user must be a member of the gpio group. The `pi` user is a member by default, other users need to be added manually. To check your user, use `whoami`
    - `$ sudo usermod -a -G gpio <username>`
2. Build the program
    - `$ make main`
3. Run the program
    - default arguments: `$ make run`
    - custom port: `$ sudo ./main <port number>`

## Client Set Up

1. Build the program
    - `$ make`
2. Run the program
    - `$ make run`

## Remote Syntax

- `shutdown`: shuts down this program
- "`operateMode`-`motorNum`"
    - `operateMode`: `CC`(counter-clockwise) or `CW`(clockwise)
    - `motorNum`: 1 to 6
    - examples 
        - `CC-3`
        - `CW-6`

## Pin Out

### Motor selection

|GPIO 17|GPIO 27|GPIO 22|Selection|
|----|----|----|----|
|0|0|1|M1|
|0|1|0|M2|
|0|1|1|M3|
|1|0|0|M4|
|1|0|1|M5|
|1|1|0|M6|

### Operation

|GPIO 5|GPIO 6|Operation|
|----|----|----|
|x|0|NOP|
|0|1|Clockwise rotation|
|1|1|counter-clockwise rotation|
