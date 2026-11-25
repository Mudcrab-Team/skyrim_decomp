# 0xf7c7f0 FloatControllerCtorLeaff7c7f0::FloatControllerCtorLeaff7c7f0

<!-- tags: method/sibling, sibling/fo4, method/diagnostic -->

- Function: 0xf7c7f0 FloatControllerCtorLeaff7c7f0::FloatControllerCtorLeaff7c7f0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: other
- Best score: 75/75 aligned bytes
- Attempts: 2

## What differed
The first comparison aligned the instructions but lacked a binding for the base destructor in exception cleanup.

## Spellings tried that did not help
- Automatic bindings resolved the normal calls but omitted the exception-cleanup reference.

## Spelling that fixed it
Providing the independently observed private base-destructor binding allowed the full comparison to pass.
