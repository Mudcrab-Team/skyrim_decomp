// Source exposure: binary-analysis; no external implementation source reused.
// Static176c460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c460*);
    virtual void release(Static176c460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c460*);
struct Static176c460 {
    void* value;
    Static176c460();
    ~Static176c460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
