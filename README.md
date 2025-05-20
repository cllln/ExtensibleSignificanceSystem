An out-of-the-box significance system with easy extensibility for custom optimization strategies。

You Need:

1.Add these configs in DefaultEngine.ini, In your project.

[/Script/SignificanceManager.SignificanceManager]
SignificanceManagerClassName=/Script/ExtensibleSignificanceSystem.ExtensibleSignificanceManager

2.Inherit USignificanceOptimizationStrategySettings classes to configure your own optimization strategies

3.ProjectSettings->Extensible Significance Settings Set your optimization strategies classes
![alt text](image.png)

You can inherit USignificanceCalculateStrategyBase class to implement your own Significance calculation strategy. And inherit UExtensibleOptimizationStrategyBase class to implement your own optimization strategies. It's very scalable.