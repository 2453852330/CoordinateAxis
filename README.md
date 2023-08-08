# CoordinateAxis
ue4.26 runtime coordinate axis system

## how to use :

```
before use this plugin , you need add a custom collision object;
Project Settings -> Engine -> Collision -> Object Channels -> New Object Channel -> Named:CoordinateAxis
```

```
check the axis actor's static mesh componet's collison settings is :
Collision Presets: Custom
Collision Enabled: Query Only
Object Type: CoordinateAxis
Collision Responses: Set All To Ignore
```

```
Get helper from BP_AxisChecker + BP_PlayerContoller_DebugAxis
```
## note :
注意InputMode的设置,如果Mouse的状态是capturing,那么获取到的MousePos是定值,会导致出错;

