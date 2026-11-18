// Source exposure: binary-analysis; no external implementation source reused.
// Static173e460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e460*);
    virtual void release(Static173e460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e460*);
struct Static173e460 {
    void* value;
    Static173e460();
    ~Static173e460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
