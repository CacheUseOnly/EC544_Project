# Controller

*need a better title for this readme*

Client example
```
./controller 44-2 67-1 48-5 91-2
44-2
67-1
48-5
91-2
disconnect
```

Server example
```
> make run
sudo ./main 54400
>>> 44-2
select motor 2
set position to 44
>>> 67-1
select motor 1
set position to 67
>>> 48-5
select motor 5
set position to 48
>>> 91-3
select motor 3
set position to 91
>>> disconnect
disconnect...
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
- "`position`-`motorNum`"
    - `postition`: 0 - 99
    - `motorNum`: 1 to 6
    - examples 
        - `24-3`
        - `79-6`

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
|`value`|1|set motor position|
