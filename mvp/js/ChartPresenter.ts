import {HarmonicData} from "./HarmonicData";
import {EventType} from "./event/EventType";

export class ChartPresenter {
    private _harmonicsList: Array<HarmonicData>;
    private _selectedHarmonicIndex: number;

    private _changeDataListEvent: EventTarget;
    private _changeSelectedHarmonicEvent: EventTarget;

    constructor() {
        this._selectedHarmonicIndex = null;
        this._harmonicsList = [];
    }

    changeDataListEvent() {
        return this._changeDataListEvent;
    }

    changeSelectedHarmonicEvent() {
        return this._changeSelectedHarmonicEvent;
    }

    addHarmonic(data: HarmonicData) {
        this._harmonicsList.push(data);

        this._dispatchChangeDataListEvent();
    }

    removeHarmonic(index: number) {
        if (0 > index || index >= this._harmonicsList.length)
        {
            throw new Error("index out of range");
        }
        this._harmonicsList.splice(index, 1);

        this._dispatchChangeDataListEvent();
    }
    
    _dispatchChangeDataListEvent() {
        this._changeDataListEvent.dispatchEvent(new Event(EventType.CHANGE_HARMONICS_LIST));
    }

    _dispatchChangeSelectedHarmonicEvent() {
        this._changeDataListEvent.dispatchEvent(new Event(EventType.CHANGE_SELECTED_HARMONIC));
    }
}