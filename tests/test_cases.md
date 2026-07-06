| Input                          | Expected Result                  |
| ------------------------------ | -------------------------------- |
| `John123`                      | Valid username                   |
| `_john`                        | Invalid (must begin with letter) |
| `averyveryverylongusername...` | Invalid length                   |
| `test@wisc.edu`                | Valid email                      |
| `test@.edu`                    | Missing domain                   |
| `Password1`                    | Valid password                   |
| `password1`                    | Missing uppercase                |
| `PASSWORD1`                    | Missing lowercase                |
