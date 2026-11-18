// Source exposure: binary-analysis; no external implementation source reused.
// Static1788520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788520*);
    virtual void release(Static1788520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788520*);
struct Static1788520 {
    void* value;
    Static1788520();
    ~Static1788520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
