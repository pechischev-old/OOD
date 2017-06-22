
export enum FunctionType {
    SIN,
    COS
};

export class HarmonicData {
    private _amplitude: number;
    private _function: FunctionType;
    private _frequency: number;
    private _phase: number;

    constructor() {
        this._amplitude = 1;
        this._phase = 0;
        this._frequency = 1;
        this._function = FunctionType.SIN;
    }

    setAmplitude(amplitude: number) {
        this._amplitude = amplitude;
    }

    amplitude() {
        return  this._amplitude;
    }

    setFunction(func: FunctionType) {
        this._function = func;
    }

    getFunction() {
        return this._function;
    }

    setFrequency(frequency: number) {
        this._frequency = frequency;
    }

    frequency() {
        return this._frequency;
    }

    setPhase(phase: number) {
        this._phase = phase;
    }

    phase() {
        return this._phase;
    }

    calculateAt(x: number) {
        const func = (this._function == FunctionType.SIN) ? Math.sin : Math.cos;
        return this._amplitude * func(this._frequency * x + this._phase);
    }
}