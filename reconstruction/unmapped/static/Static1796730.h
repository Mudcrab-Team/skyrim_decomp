// Source exposure: binary-analysis; no external implementation source reused.
// Static1796730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796730*);
    virtual void release(Static1796730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796730*);
struct Static1796730 {
    void* value;
    Static1796730();
    ~Static1796730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
