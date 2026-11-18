// Source exposure: binary-analysis; no external implementation source reused.
// Static175b110, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b110;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b110*);
    virtual void release(Static175b110*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b110*);
struct Static175b110 {
    void* value;
    Static175b110();
    ~Static175b110() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
