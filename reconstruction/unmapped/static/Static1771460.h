// Source exposure: binary-analysis; no external implementation source reused.
// Static1771460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771460*);
    virtual void release(Static1771460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771460*);
struct Static1771460 {
    void* value;
    Static1771460();
    ~Static1771460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
