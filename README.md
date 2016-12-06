# ballgame
Final CS1D project, Spring 2016: Take me out to the ball game. Written in C++ using the QT GUI framework.

## Code Style
- Adhere to the [Google C++ style](https://google-styleguide.googlecode.com/svn/trunk/cppguide.html)

## Adding new code/ Directory Structure
Keeping our code in seperate directories helps keep our code more maintainable and easy to follow.
You can use this below table to help decide where your code should go.

### new files
- put **.h** files into `include/`
- put **.cpp** files into `src/`
- put **.ui** files into `ui/`
- put **images,etc** into `assets/`

##### In the QT **.pro** file (example)
- `src/mainwindow.cpp`
- `include/mainwindow.h`
- `ui/mainwindow.ui`



## Commenting
- Comment as required for Doxygen support, refer to the [Doxygen Manual](http://www.stack.nl/~dimitri/doxygen/manual/index.html)
- Use a commenting style like this:
```
/** addToCart
 * @brief shoppingMenu::addToCart this method adds an item to the cart
 * @param currentIndex the index of the restaurant to add an item to
 */
 void shoppingMenu::addToCart(int currentIndex)
```
Or something like this
```
///*********************************************************************
///addToCart
///@brief shoppingMenu::addToCart - this method adds an item to the cart
///@param currentIndex the index of the restaurant to add an item to
void shoppingMenu::addToCart(int currentIndex)
```

The idea is that you want to use a commenting style that doxygen will understand and be able to pick up.
so using things like `///comment` and `/** a comment */` will let doxygen pickup additional information about our code.
## Workflow
Pleaes note: do not push to master. Master is going to be our release branch.

Workflow should be approached in the following way:
#### Guidelines
- never push to master
- push your changes to a feature branch checked out of our testing branch.
-- it is okay to push to testing, but most changes should be made in your own feature branch.
- every release (sprint review) we will stage and test our changes in the testing branch. When we deem the branch ready for commitment we will merge the branch into master and create a release.

### Feature Branches
A great way to keep things organized is to check our a branch * from testing * for the feature (or user story) that you are working on.

#### Example:
Let's say you are working on a new feature fo the story [Admin] View Stadium
You would first checkout a branch from testing by following these steps:
- ```git checkout testing```
- ```get checkout -B view-stadium```
- ```git push origin view-stadium```

The idea is that you want to check out your new feature branch **FROM TESTING and not MASTER** <- this is extremely important!
You branch out from testing into a new branch called view-stadium
And then you push your new branch to the remote repo on github.


### Merging your feature branch back into testing
When your done with your feature and want to move things back into testing to be integrated into the project (and tested by the rest of the group) you can follow these steps.

#### Example:
You are now down with your view-stadium feature. You added some classes, a ui, etc.. and you want to merge your branch back in, follow these steps.

``` git checkout view-stadium ```
- make sure you are own your branch that you want to merge into testing

``` git fetch origin testing ```
- fetches the most recent changes form the testing branch

``` git rebase origin/testing ```
- this starts the rebasing process. What you are doing is applying changes from testing to your branch.
- you'll need to resolve merge conflicts most likely. If you need help on that go here: https://githowto.com/resolving_conflicts

After your branch has been rebased, simply go to github.com/Veleroth/ballgame and find your branch and create a pull request to merge your feature branch into testing.
Once approved the branch will then be merged into testing.

## Testing someone else's branch
Testing another group members branch is simple. provided we are following the required workflow you can perform these steps:
``` git checkout <branch-name> ```
- where <branch-name> is the name of the person's branch you wish to check out.


