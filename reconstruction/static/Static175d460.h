// Source exposure: binary-analysis; no external implementation source reused.
// Static175d460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d460*);
    virtual void release(Static175d460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d460*);
struct Static175d460 {
    void* value;
    Static175d460();
    ~Static175d460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
