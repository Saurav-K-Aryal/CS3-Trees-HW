# Computer Science III - Data Structures Class

Contributors:
- Anurrag Rijal
- Ashish Adhikari
- Devendra Shah
- Saurav Keshari Aryal


Overview:

Implementing the following flavors of trees in C++ and realworld run-time analysis to insert and then delete all values from 1 to 1,000,000.


Results over three experimental runs and average(in seconds):

**1 million insertions:**

* AVLTree -> (2.24652 + 1.96817 + 2.00946) / 3 = 2.07472 s
* 2-3 B Tree -> (0.594022 + 0.571282 + 0.544392) / 3 = 0.56990 s
* Red Black Tree -> (1.09105 + 0.943154 + 0.943515) / 3 = 0.99257 s
* Binary Search Tree -> (1.03495 + 0.893022 + 0.835576) / 3 = 0.92118 s

**1 million deletions:**

* AVLTree -> (0.312913 + 0.278984 + 0.287982) / 3 = 0.879879 s
* 2-3 B Tree -> (0.210755 + 0.193194 + 0.192079) / 3 = 0.198676 s
* Red Black Tree -> (0.247717 + 0.228094 + 0.226969) / 3 = 0.234260 s
* Binary Search Tree -> (0.187757 + 0.172333 + 0.175951) / 3 = 0.178680 s